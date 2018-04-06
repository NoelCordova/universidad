#!/usr/bin/env python

foto= open("../../Desktop/foto.jpg", "rb")
foto2= open("../../Desktop/foto2.jpg", "wb")

newphoto= foto.read()
foto2.write(newphoto)

foto.close()
foto2.close()
