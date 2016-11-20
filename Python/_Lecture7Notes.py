import matplotlib.pyplot as plt
import matplotlib.image as mpimg

imgDolphin = mpimg.imread('dolphin_swimming.jpg')
print imgDolphin
imgPLdolphin = plt.imshow(imgDolphin)
plt.show()

print imgDolphin.shape
