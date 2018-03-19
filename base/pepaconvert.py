#!/usr/bin/python

import sys, getopt
import xml.etree.ElementTree as ET

def main(argv):
	inputfile = 'dessinout.svg'
	outputfile = 'output.svg'
	try:
		opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
	except getopt.GetoptError:
		print('pepaconvert.py -i <inputfile> -o <outputfile>')
		sys.exit(2)
	for opt, arg in opts:
		if opt == '-h':
			print('test.py -i <inputfile> -o <outputfile>')
			sys.exit()
		elif opt in ("-i", "--ifile"):
			inputfile = arg
		elif opt in ("-o", "--ofile"):
			outputfile = arg

	tree = ET.parse(inputfile)
	root = tree.getroot()
	root.set('width','600mm') 
	root.set('height','400mm')
	root.set('viewBox','0 0 600 400')
	for child in root[0]:
		if child.get('stroke-dasharray') is not None:
			child.set('style',child.get('style').replace("#000000","#00ff00").replace('stroke-width:0.1','stroke-width:0.254'));
			child.attrib.pop('stroke-dasharray');
		else:
			child.set('style',child.get('style').replace("#000000","#ff0000").replace('stroke-width:0.1','stroke-width:0.254'));
	tree.write(outputfile)
	

if __name__ == "__main__":
   main(sys.argv[1:])


