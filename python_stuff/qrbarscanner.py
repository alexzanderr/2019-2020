
import cv2
from pyzbar import pyzbar as pyz
import argparse

text = "D:\\__Alexzander_files__\\computer_science\\python_stuff\\" \
        "andrew_packages\\photos\\andrew_qr.png"
url = "D:\\__Alexzander_files__\\computer_science\\python_stuff\\" \
        "andrew_packages\\photos\\hackerrank.png"
test = "D:\\__Alexzander_files__\\computer_science\\python_stuff\\" \
        "andrew_packages\\photos\\test.png"
barcode = "D:\\__Alexzander_files__\\computer_science\\python_stuff\\" \
          "andrew_packages\\photos\\barcode1.png"

class DecodeBarCode:

    def __init__(self, path):
        self.image_path = path

    def DisplayImage(self):
        image = cv2.imread(self.image_path)
        cv2.imshow("Bar Code Image", image)
        cv2.waitKey(0)

    def DecodeBarImage(self):
        image = cv2.imread(self.image_path)
        decoded = pyz.decode(image)
        return decoded

    def PrintContent(self):
        decoded = self.DecodeBarImage()
        attributes = decoded[0]
        for elem in attributes:
            print(elem)

    def __str__(self):
        print(self.DecodeBarImage())
        return ""

class DecodeQrCode:

    def __init__(self, path):
        self.image_path = path

    def DisplayImage(self):
        image = cv2.imread(self.image_path)
        cv2.imshow("Bar Code Image", image)
        cv2.waitKey(0)

    def DecodeQrImage(self):
        image = cv2.imread(self.image_path)
        decoded = pyz.decode(image)
        return decoded

    def __str__(self):
        print(self.DecodeBarImage())
        return ""

    def PrintContent(self):
        decoded = self.DecodeQrImage()
        attributes = decoded[0]
        for elem in attributes:
            print(elem)

if __name__ == '__main__':
    barcode = DecodeBarCode(barcode)
    barcode.DisplayImage()
    print(barcode)