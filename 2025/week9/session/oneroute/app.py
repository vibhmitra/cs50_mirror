from flask import Flask, render_template, request

app = Flask(__name__)

# single route handles both REQUESTs
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        return render_template("greet.html", username=name)
    else:
        return render_template("index.html")
