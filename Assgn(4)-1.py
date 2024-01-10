num = int(input("Enter a number: "))  
sum=0
if num<0:  
   print("Enter a positive number")  
else:    
   while(num>0):  
       sum+=num  
       num-=1  
   print("The sum is",sum)  
