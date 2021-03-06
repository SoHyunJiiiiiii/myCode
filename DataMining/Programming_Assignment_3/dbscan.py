from math import sqrt, pow
class DBSCAN:
   def __init__(self):
     import sys
     inputfileName = sys.argv[1]
     self.name = 'DBSCAN'
     self.DB = [] #Database
     self.cluster_size = int(sys.argv[2])
     self.esp = int(sys.argv[3]) #neighborhood distance for search
     self.MinPts = int(sys.argv[4]) #minimum number of points required to form a cluster
     self.cluster_inx = -1
     self.cluster = []

    #this is a mocking data just for test
     vecPoint = []
     tempArray = []
     f = open(inputfileName,'r')
     while True:
          line = f.readline()
          line = line.strip()
          if not line: break
          split_line = line.split('\t')
          tempArray.insert(1,split_line)
          #print tempArray[0][0],tempArray[0][1],tempArray[0][2]
          vecPoint.append(Point(float(tempArray[0][1]),float(tempArray[0][2]),int(tempArray[0][0])));
          tempArray.pop(0)
     f.close()
     self.DB = vecPoint;


   def DBSCAN(self):
      for i in range(len(self.DB)):
         p_tmp = self.DB[i]
         if (not p_tmp.visited):
            #for each unvisited point P in dataset
            p_tmp.visited = True
            NeighborPts = self.regionQuery(p_tmp)
            if(len(NeighborPts) < self.MinPts):
              #that point is a noise
               p_tmp.isnoise = True
              #print p_tmp.show(), 'is a noise'
            else:
               if((self.cluster_inx+1) < self.cluster_size):
                  self.cluster.append([])
                  self.cluster_inx = self.cluster_inx + 1
                  self.expandCluster(p_tmp, NeighborPts)
               else:
                   p_tmp.isnoise = True

   def expandCluster(self, P, neighbor_points):
     self.cluster[self.cluster_inx].append(P)
     iterator = iter(neighbor_points)
     while True:
       try:
         npoint_tmp = iterator.next()
       except StopIteration:
         # StopIteration exception is raised after last element
         break
       if (not npoint_tmp.visited):
         #for each point P' in NeighborPts
         npoint_tmp.visited = True
         NeighborPts_ = self.regionQuery(npoint_tmp)
         if (len(NeighborPts_) >= self.MinPts):
           for j in range(len(NeighborPts_)):
             neighbor_points.append(NeighborPts_[j])
       if (not self.checkMembership(npoint_tmp)):
         #if P' is not yet member of any cluster
         self.cluster[self.cluster_inx].append(npoint_tmp)
#else:
#        print npoint_tmp.show(), 'is belonged to some cluster'

   def checkMembership(self, P):
     #will return True if point is belonged to some cluster
      ismember = False
      for i in range(len(self.cluster)):
         for j in range(len(self.cluster[i])):
            if (P.x == self.cluster[i][j].x and P.y == self.cluster[i][j].y):
               ismember = True
      return ismember

   def regionQuery(self, P):
   #return all points within P's eps-neighborhood, except itself
      pointInRegion = []
      for i in range(len(self.DB)):
          p_tmp = self.DB[i]
          if (self.dist(P, p_tmp) < self.esp and P.x != p_tmp.x and P.y != p_tmp.y):
            pointInRegion.append(p_tmp)
      return pointInRegion

   def dist(self, p1, p2):
   #return distance between two point
     dx = (p1.x - p2.x)
     dy = (p1.y - p2.y)
     return sqrt(pow(dx,2) + pow(dy,2))
class Point:
     def __init__(self, x = 0, y = 0, pid = 0, visited = False, isnoise = False):
          self.x = x
          self.y = y
          self.pid = pid;
          self.visited = False
          self.isnoise = False
     def show(self):
          return self.pid

if __name__=='__main__':

      #vecPoint = [Point(11,3), Point(10,4), Point(11,5), Point(12,4), Point(13,5), Point(12,6), Point(6,10), Point(8,10), Point(5,12), Point(7,12)]

      #Create object && Load data into object
      dbScan = DBSCAN()
      #dbScan.DB = vecPoint;

      #Do clustering
      dbScan.DBSCAN()


      #Show result cluster
      for i in range(len(dbScan.cluster)):
         #print 'Cluster: ', i
         output_fileName = "input1_cluster_"+str(i)+".txt"
         fw = open(output_fileName,'w')
         for j in range(len(dbScan.cluster[i])):
             pid_result = str(dbScan.cluster[i][j].show()) + "\n"
             fw.write(pid_result)
      fw.close()
