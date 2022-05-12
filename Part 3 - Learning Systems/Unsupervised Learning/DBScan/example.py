from random import choices

# initialize settings
depth_img_path = "/Path/to/the/image/0000323.png"
normal_img_path = "/Path/to/the/image/0000323.jpg"
eps = 4.7
min_samples = 50

# load image data
# image size is 730x530
depth_img = plt.imread(depth_img_path)
normal_img = plt.imread(normal_img_path)
# preprocess of pixel data
points = []
for rindex, row in enumerate(depth_img):
	for cindex, depth in enumerate(depth_img[rindex]):
		points.append([cindex, rindex, int(depth*450)])

arr = numpy.array(points)

# perform DBSCAN
db = DBSCAN(eps=eps, min_samples=min_samples).fit(arr)

# Output result
## generate label colours
label_colours = [choices(range(256), k=3) for c in list(range(0,max(db.labels_)+1))]
## convert labels to RGB picture
cluster_img = []
for index, label in enumerate(db.labels_):
	x = index % 730
	y = int(index / 730)
	c = label_colours[label]
	if x == 0:
		cluster_img.append([])
	cluster_img[y].append(c)
fig = plt.figure(figsize=(32, 32))
fig.add_subplot(1, 3, 1)
plt.imshow(normal_img)
plt.axis('off')
plt.title("Origin")
fig.add_subplot(1, 3, 2)
plt.imshow(depth_img)
plt.axis('off')
plt.title("Depth")
fig.add_subplot(1, 3, 3)
plt.imshow(cluster_img)
plt.axis('off')
plt.title("Clustered")
plt.show()