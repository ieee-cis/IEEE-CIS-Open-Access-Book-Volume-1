import os
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import numpy as np
from sklearn.cluster import DBSCAN
from sklearn.neighbors import NearestNeighbors
from kneed import KneeLocator
from matplotlib.legend_handler import HandlerLine2D


img_width = 730 # width of the image in the folder below
path = '/path/to/the/image/folder'
file = list(os.listdir(path + '/image/'))[0]
[id, ext] = (file.split('.'))
depth_img_path = path + '/depth/' + id+'.png'
normal_img_path = path + '/image/' + id+'.jpg'
name = id
depth_img = plt.imread(depth_img_path)
normal_img = plt.imread(normal_img_path)
points = []
for rindex, row in enumerate(depth_img):
    for cindex, depth in enumerate(depth_img[rindex]):
        points.append([cindex, rindex, int(depth*450)])
arr = np.array(points)
min_samples = 4
print('find eps start')
nbrs = NearestNeighbors(n_neighbors=min_samples).fit(arr)
distances, indices = nbrs.kneighbors(arr)
distances = np.sort(distances[:, 1], axis=0)[::-1]
# distances = distances[:500]

kneedle = KneeLocator(range(1, len(distances)+1),  # x values
                        distances,  # y values
                        S=1.0,  # parameter suggested from paper
                        curve='convex',  # parameter from figure
                        direction='decreasing')  # parameter from figure
eps = round(kneedle.knee_y, 3)
print('find eps end')

print('dbscan start')
db = DBSCAN(eps=eps, min_samples=min_samples).fit(arr)
labels = db.labels_
print('dbscan end')

label_colours = cm.gist_rainbow(np.linspace(0, 1, len(set(db.labels_))))
label_colours = np.insert(label_colours, 0, [1, 1, 1, 1], axis=0)

segment_img = []
for l_index, label in enumerate(labels):
    x = l_index % img_width # when this is 0, it means begin of a new line
    y = int(l_index / img_width)
    c = label_colours[label]
    if x == 0:
        segment_img.append([]) # add another array to hold data for the new line
    segment_img[y].append(c)

fig = plt.figure()
fig.add_subplot(2, 2, 1)
plt.imshow(normal_img)
plt.axis('off')
plt.title('Origin')

fig.add_subplot(2, 2, 2)
plt.imshow(depth_img)
plt.axis('off')
plt.title('Depth')

ax = fig.add_subplot(2, 2, 3)
plt.plot(distances[:300], label = 'Data')
plt.vlines(x=eps, ymin=0, ymax=100, linestyle='--', label = 'Elbow', colors = 'orange')
plt.legend()
ax.annotate('ε = ' + str(eps), xy=(kneedle.knee, kneedle.knee_y), xytext=(kneedle.knee + 10, kneedle.knee_y + 5), fontsize = 20)
plt.title('Knee Point')

fig.add_subplot(2, 2, 4)
plt.imshow(segment_img)
plt.axis('off')
plt.title('Clustered')

plt.show()