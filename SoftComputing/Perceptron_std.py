# organize imports
import numpy as np
import matplotlib.pyplot as plt

# function to plot graph for binary inputs
def plot_graph(data, idx_subplot, title):
	xs = np.repeat(range(len(data)), 2)
	ys = np.repeat(data, 2)
	xs = xs[1:]
	ys = ys[:-1]
	plt.subplot(5,1,idx_subplot)
	plt.title(title)
	plt.plot(xs, ys)
	plt.ylim(-0.5, 1.5)


if __name__ == "__main__":
	###########################################
	# INPUT DATA
	###########################################
	# input data
	in_a = np.array([0,0,1,1,0])
	in_b = np.array([0,1,0,1,0])

	# output ground truth (OR gate)
	o_gt = np.array([0,1,1,1,0])

	# weights
	w = np.random.randn(1,2)
	bias = np.random.randn(1,1)

	print "Weights before training - {}".format(w)
	print "Bias before training - {}".format(bias)

	###########################################
	# HYPER-PARAMETERS
	###########################################
	learning_rate = 1
	epochs = 10

	###########################################
	# TRAINING
	###########################################
	x_axis = []
	y_axis = []
	for e in range(epochs):
		error = 0
		for a, b, o in zip(in_a, in_b, o_gt):
			# weighted sum
			ws = w[0][0]*a + w[0][1]*b
			# activation
			summed = ws + bias
			# initialize output to zero
			y = 0
			if summed >= 0:
				y = 1
			else:
				y = 0
			
			# calculate the error
			error = o - y
			
			# update rule
			dw0 = learning_rate * (error) * a
			dw1 = learning_rate * (error) * b

			# update weights
			w[0][0] = w[0][0] + dw0
			w[0][1] = w[0][1] + dw1

			# update bias too!
			bias = bias + (learning_rate * error)
			
			# for visualization purpose
			x_axis.append(e)
			y_axis.append(error)

	print "Weights after training - {}".format(w)
	print "Bias after training - {}".format(bias)

	###########################################
	# TESTING
	###########################################
	perceptron_output = []
	for a, b in zip(in_a, in_b):
		# weighted sum
			ws = w[0][0]*a + w[0][1]*b
			# activation
			summed = ws + bias
			# initialize output to zero
			if summed >= 0:
				perceptron_output.append(1)
			else:
				perceptron_output.append(0)

	# summary
	print "\nInput A - {}".format(in_a)
	print "Input B - {}".format(in_b)
	print "Ground truth - {}".format(o_gt)
	print "Output - {}".format(perceptron_output)

	# display the plot
	plot_graph(in_a, 1, "Input A")
	plot_graph(in_b, 2, "Input B")
	plot_graph(o_gt, 3, "Ground Truth")
	plot_graph(perceptron_output, 4, "Actual Output")

	plt.subplot(5,1,5)
	plt.title("Epochs vs Error")
	plt.plot(x_axis, y_axis)
	plt.show()