# -*- coding: utf-8 -*-
from math import log
import operator
#read trainfile and Set dataset,label
def createDataSet(trainfileName):
	data = []
	label = []
	f = open(trainfileName,'r')
	line = f.readline()
	line = line.strip()
	split_line = line.split('\t')
	label.extend(split_line)
	while True:
		line = f.readline()
		line = line.strip()
		if not line: break
		split_line = line.split('\t')
		data.append(split_line)
	f.close()

	return data,label

def GetEntropy(dataSet):
    numEntropy = len(dataSet)
    labelCounts = {}
    for testVec in dataSet:  # the the number of unique elements and their occurance
        currentLabel = testVec[-1]
        if currentLabel not in labelCounts.keys(): labelCounts[currentLabel] = 0
        labelCounts[currentLabel] += 1
    entropy = 0.0
    for key in labelCounts:
        prob = float(labelCounts[key]) / numEntropy
        entropy -= prob * log(prob, 2)
    return entropy


def splitDataSet(dataSet, split, value):
    resultDataSet = []
    for array in dataSet:
        if array[split] == value:
            spliitted = array[:split]  # split dataSet
            spliitted.extend(array[split + 1:])
            resultDataSet.append(spliitted)
    return resultDataSet


def GetBestSplitCriterion(dataSet):
    numCriterion = len(dataSet[0]) - 1  # the last column is used for the labels
    baseEntropy = GetEntropy(dataSet)
    bestInfoGain = 0.0;
    bestCriterion = -1
    for i in range(numCriterion):  # Best Spilit기준을 찾기위해 모든기준에 대해서 for문을 돌림
        CriterionList = [example[i] for example in dataSet]
        uniqueVals = set(CriterionList)
        newEntropy = 0.0
        for value in uniqueVals:
            subDataSet = splitDataSet(dataSet, i, value)
            prob = len(subDataSet) / float(len(dataSet))
            newEntropy += prob * GetEntropy(subDataSet)

        infoGain = baseEntropy - newEntropy  # calculate the Information gain

        if (infoGain > bestInfoGain):  # Max Information gain구하기
            bestInfoGain = infoGain	#Max Information = best Information gain
            bestCriterion = i
    return bestCriterion  # returns an integer of bestCriterion


def majorityCnt(classList):
    classCount = {}
    for vote in classList:
        if vote not in classCount.keys(): classCount[vote] = 0
        classCount[vote] += 1
    sortedClassCount = sorted(classCount.iteritems(), key=operator.itemgetter(1), reverse=True)
    return sortedClassCount[0][0]


def createTree(dataSet, labels):
    # extracting data
    classList = [example[-1] for example in dataSet]
    if classList.count(classList[0]) == len(classList):
        return classList[0]  # stop splitting when all of the classes are equal
    if len(dataSet[0]) == 1:  # stop splitting when there are no more Criterion in dataSet
        return majorityCnt(classList)
    # build a descisionTree using Information Gain
    bestCriterion = GetBestSplitCriterion(dataSet)
    bestCriterionLabel = labels[bestCriterion]
    myTree = {bestCriterionLabel: {}}


    del (labels[bestCriterion])
    CriterionValues = [example[bestCriterion] for example in dataSet]
    uniqueVals = set(CriterionValues)

    for value in uniqueVals:
        subLabels = labels[:]  # copy all of labels into subLabels
        myTree[bestCriterionLabel][value] = createTree(splitDataSet(dataSet, bestCriterion, value), subLabels)
    return myTree

def classify(inputTree, CriterionLabels, testList):
	firstAttr = inputTree.keys()[0] #inputTree의 루트 속성 기준
	secondDict = inputTree.get(firstAttr,"NONE")	#firstAttr의 partition Directory..루트에 해당하는 하위 트리 전체
	CriterionIndex = CriterionLabels.index(firstAttr)	#fitstAttr의 인덱스
	key = testList[CriterionIndex]	#testList가 포함되는 firstAttr의 파티션

	valueOfCriterion = secondDict.get(key,"NONE")	#key의 partition Directory...key값에 해당하는 하위트리 전체
	if isinstance(valueOfCriterion, dict):	#하위트리안에 여전히 Directory가 포함됬는지 확인
		classLabel = classify(valueOfCriterion, CriterionLabels, testList)	#여전히 Directory라면, 재귀로 다시 분류
	else:	#Directory가 아니라면,
		classLabel = valueOfCriterion	#해당하는 classLabel을 리턴함
	return classLabel

#현재 해당하는 클래스 라벨이 없을때, 다수결 판정을 위한 함수
#분류 완성된 descision tree,text_array는 확인해야할 데이터배열
def findAttributeList(descisionTree,CriterionLabels,test_array,Attr_list,dataSet):


	firstAttr = descisionTree.keys()[0] #descisionTree의 루트 속성 기준
	#print("fistStr : "+firstAttr)
	secondDict = descisionTree.get(firstAttr,"NONE")	#firstAttr의 partition Directory..루트에 해당하는 하위 트리 전체
	#print("secondDict : " + str(secondDict))
	CriterionIndex = CriterionLabels.index(firstAttr)	#fitstAttr의 인덱스
	#print("CriterionIndex : " + str(CriterionIndex))
	key = test_array[CriterionIndex]	#testList가 포함되는 firstAttr의 파티션
	#print("key : " + str(key))
	Attr_list[firstAttr]=key

	valueOfCriterion = secondDict.get(key,"NONE")	#key의 partition Directory...key값에 해당하는 하위트리 전체
	#print("valueOfCriterion : " + str(valueOfCriterion))
	if isinstance(valueOfCriterion, dict):	#하위트리안에 여전히 Directory가 포함됬는지 확인
		#print("is instance: "+str(valueOfCriterion))
		findAttributeList(valueOfCriterion,CriterionLabels,test_array,Attr_list,dataSet)	#여전히 Directory라면, 재귀로 다시 분류
	else :
		print Attr_list
		findMajorityClassLabel(dataSet,Attr_list)

def findMajorityClassLabel(dataSet):
	#리스트 중복된 클래스라벨 제거
	label_list = []
	for arraySet in dataSet:
		label_list.append(arraySet[-1])
	label_list = list(set(label_list))
	#count세기
	count_array=[0]*len(label_list)
	for i in range(0,len(label_list)):
		for array in text_data:
			for j in range(0,len(array)):
				if label_list[i] == array[j]:
					count_array[i]+=1
	temp = count_array;
	temp.sort()
	for i in range(0,len(count_array)):
		if(temp[-1]==count_array[i]):
			return label_list[i]

#main함수
import sys
trainfileName = sys.argv[1]
textfileName = sys.argv[2]
resultfileName = sys.argv[3]

fr = open(textfileName,'r')
fw = open(resultfileName,'w')

# collect data
myDat, labels = createDataSet(trainfileName)
text_data = []
Criterion = (labels[0:len(labels)-1])

for i in range(0,len(labels)):
	fw.write(str(labels[i])+"\t")
fw.write("\n")

line = fr.readline()
while True:
	line = fr.readline()
	line = line.strip()
	if not line: break
	split_line = line.split('\t')
	text_data.append(split_line)

#build a tree
mytree = createTree(myDat, labels)
#print(mytree)

attr_list = {}
for array in text_data:
	answer = classify(mytree,Criterion,array)
	if answer != "NONE" :
		array.append(answer)
	else :	#해당 클래스가 라벨이 없을 경우..다수결
		# findAttributeList(mytree,Criterion,array,attr_list,text_data)
		array.append(findMajorityClassLabel(text_data))


tempstring=""
for array in text_data:
	for i in range(0,len(array)):
		tempstring = tempstring + str(array[i])
		if(len(labels)>i):
			tempstring += "\t"
		# else :
		# 	print "tab안넣어!"
	tempstring += "\n"
fw.write(tempstring)
#fw.write(str(array[i])+"\t")
#fw.write("\n")
#findMajorityClassLabel(text_data)
