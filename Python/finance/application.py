import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# global var for functions to use SQL() function - from cs50 lib
db = SQL("sqlite:///finance.db")

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():

    if request.method == "POST":
        # get stock data
        symbol = lookup(request.form.get("symbol"))
        # variable for the number of shares user wants
        shares = request.form.get("shares")
        # get user's amount of money listed on databse
        user = db.execute("SELECT cash FROM users WHERE id = :user_id", user_id=session["user_id"])

        if symbol == '' or symbol == False:
            return apology("Enter a valid symbol")
        if float(shares) < 0:
            return apology("Enter a positive amount of shares")

        # money user has
        cash = user[0]['cash']
        price_per_share = symbol['price']
        total_cost = price_per_share * float(shares)

        if total_cost > cash:
            return apology("Not enough money to buy")

        db.execute("UPDATE users SET cash = cash - :price WHERE id = :user_id", price=total_cost, user_id=session["user_id"])


        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES(:user_id, :symbol, :shares, :price)",
                   user_id=session["user_id"],
                   symbol=request.form.get("symbol"),
                   shares=shares,
                   price=price_per_share)

        flash("Success!")

        return redirect(url_for("index"))
    
    else:
        return render_template("buy.html")



@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    return jsonify("TODO")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        symbol = lookup(request.form.get("symbol"))

        if not symbol:
            #return apology("Not a stock symbol. Try again")
            return flash("Not a valid symbol!") 

        return render_template("quoted.html", symbol=symbol)

    else:
         return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":

        # make sure a username was submitted
        if not request.form.get("username"):
            return apology("Must provide username", 400)
        # make sure a password was submitted
        elif not request.form.get("password"):
            return apology("Must provide password", 400)
        # make sure password and confirmation match
        elif not request.form.get("password") == request.form.get("confirmation"):
            return apology("Passwords must match", 400)
        # hash password
        hash = generate_password_hash(request.form.get("password"))
        # add new user to database
        new_user = db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)", username=request.form.get("username"), hash=hash)

        # make sure username doesn't already exist in database
        if not new_user:
            return apology("username taken")

        # remember info of user
        session["user_id"] = new_user

        # Redirect user to home page
        return redirect(url_for("index"))

    else:
        return render_template("register.html") 
        


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
