from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def greetin():
    name = request.args.get("name", "world")
    return render_template("index.html", username=name)

@app.route("/greet", methods=["POST", "GET"])
def greetout():
    # name = request.args.get("name", "world") for get requests
    name = request.form.get("name", "world")
    return render_template("greet.html", username=name)
