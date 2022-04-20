import random
import timeit

n=int(input()) 
mat1=[]  
mat2=[] 
ans=[]
for i in range(n):  
    row = [0]*n 
    ans.append(row)
        
for i in range(n): 
   row=[]                                   
   for j in range(n): 
      row.append(random.randint(1,100))           
   mat1.append(row)                      

for i in range (n): 
   row=[]                                    
   for j in range(n): 
      row.append(random.randint(1,100))        
   mat2.append(row)    

startTime = timeit.default_timer()                                                              
for k in range(n):              #loop c
   for i in range(n):           #loop a
      for j in range(n):        #loop b
         ans[i][j] += mat1[i][k] * mat2[k][j]
stopTime = timeit.default_timer()

for i in ans: 
   print(i)
   
print('Time- ', stopTime - startTime)
