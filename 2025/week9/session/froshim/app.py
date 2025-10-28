from flask import Flask, render_template, request
from cs50 import SQL

app = Flask(__name__)

db = SQL("sqlite:///froshim.db")

SPORTS = [
    "Basketball",
    "Soccer",
    "Ultimate Frisbee",
]

# REGISTRANTS = {} # same as = dict()


@app.route("/", methods=["GET", "POST"])
def index():
    return render_template("index.html" , sports=SPORTS)

# storing using REGISTRANTS dict
# @app.route("/register", methods=["POST"])
# def register():
#     # if not request.form.get("name") or request.form.get("sport") not in SPORTS:
#     #     return render_template("failure.html")

#     name = request.form.get("name")
#     if not name:
#         return render_template("error.html", message="Missing name ❌❌❌")
#     sport = request.form.get("sport")
#     if not sport:
#         return render_template("error.html", message="Missing sport ❌❌❌")
#     if sport not in SPORTS:
#         return render_template("error.html", message="Invalid sport ❌❌❌")

#     REGISTRANTS[name] = sport  # key = value
#     return render_template("success.html")

# @app.route("/registrants")
# def registrants():
#     return render_template("registrants.html", registrants=REGISTRANTS)

# storing using database
@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Missing name ❌❌❌")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing sport ❌❌❌")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport ❌❌❌")

    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    return render_template("success.html")


@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT name, sport FROM registrants")
    return render_template("registrants.html", registrants=registrants)
