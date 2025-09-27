from PIL import Image, ImageFilter

before = Image.open("005.jpg")
after = before.filter(ImageFilter.FIND_EDGES)
after.save("edge_out.jpg")
