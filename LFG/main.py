# https://asecuritysite.com/encryption/fab?Length=10
import sys

j = 2
k = 5
m = 127  #initialisation of j, k and m

val = "83256345435434" #initiliastion of the first value

if (len(sys.argv)>1):     #Setting that val is in terms with the  system and rule we 
	val=str(sys.argv[1])    #choose
if (len(sys.argv)>2):     # Setting that m is in terms with the system and rule we
	m=int(sys.argv[2])      #choose

def conv(val):                  #forming the sequence of random numbers
	arr = []
	for i in range(len(val)):
		arr.append(int(val[i]))
	return arr

def showvals(val,j,k):          #displaying the values at each point(the sequence,
	for i in range(len(val)):     #j and k)
		if (i==j-1):  
			print ("[%3d]"%val[i], end = '')
		elif (i==k-1):  
			print ("[%3d]"%val[i], end = '')
		else:
			print ("%3d"%val[i], end = '')

s=conv(val)               #initialisation of seed

print ("j=",j," k=",k)
print ("Seed:\t",val)

if (len(s)<k):                      # length of interval must be higher than k
	print ("Value needs to be larger than 7")   #accordin to rules of LFG
	exit()

showvals(s,j,k)

for n in range(20):                 #displaying first 20 values generated
    out = (s[j-1] + s[k-1]) % m     #the method used here is addition so it is ALFG
    for i in range(len(s)-1):       #the value is then computed and displayed
      s[i] = s[i+1] 

    s[len(s)-1] = out
             
    print ("-->",out)
    showvals(s,j,k)

print ("-->",out)