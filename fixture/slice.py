import os

def seekRecip(line):
	char = ''
	word = ""
	words = []
	for it in range(1,len(line)):
		if line[it]!='|':
			word+=line[it]

		else:
			words.append(word)
			word=""
	words.append(word[:-1])
	return words

def makefilesRecip(files):
	for it in files:
		f=open(it,'w')
		f.close()


if __name__ == "__main__":
	file=""
	files=[]
	line=""
	word=""
	char=""
	i=0


	file=open("file.txt","r")
	line=file.readline()
	files=seekRecip(line)
	makefilesRecip(files)

	while line != "":
		line=file.readline()
		for char in line:
			if char != '|' and char != '\n':
				word+=char
			else:
				word+='\n'
				if(i<len(files)):
					f=open(files[i],'a')
					i=i+1
				else:
					i=0
					f=open(files[i],'a')
					i=i+1
				f.write(word)
				word=""
				f.close()



