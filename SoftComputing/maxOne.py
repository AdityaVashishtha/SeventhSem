from random import randint

MAX_ONE_REQ = 32
LARGE_NUMBER = (2**MAX_ONE_REQ-1)
INITIAL_POPULATION_COUNT = 50
CROSSOVER_CHROMOSOME_SIZE = 16
MUTATION_BITS_COUNT = 3

def convertBinary(a):  
    binary=""  
    for i in range(32):
        bit = 0 if (a&(1<<i)==0) else 1
        binary += str(bit)        
    return binary[::-1]

def setScore(a):
    count = 0
    for i in range(0,len(a)):
        if(a[i]=='1'):
            count += 1
    return count

def crossOver(a,b):
    temp = (a[:CROSSOVER_CHROMOSOME_SIZE]) + b[CROSSOVER_CHROMOSOME_SIZE  : len(b)]
    temp2 = b[:CROSSOVER_CHROMOSOME_SIZE] + a[CROSSOVER_CHROMOSOME_SIZE : len(a)]
    return temp,temp2

def mutation(a):
    for i in range(0,MUTATION_BITS_COUNT):
        mutation_index = randint(0,MAX_ONE_REQ-1)
        if(a[mutation_index]=='1'):
            a=a[:mutation_index]+'0'+a[mutation_index+1:]
        else:
            a=a[:mutation_index]+'1'+a[mutation_index+1:]
    
    return a
    

def getInitialPopulation():
    x = [ convertBinary(randint(1,LARGE_NUMBER)) for i in range(0,INITIAL_POPULATION_COUNT) ]
    return x

def rankPopulation(list):
    for passnum in range(len(list)-1,0,-1):
        for i in range(passnum):
            if setScore(list[i]) < setScore(list[i+1]):
                temp = list[i]
                list[i] = list[i+1]
                list[i+1] = temp

def nextGeneration(list):    
    rankPopulation(list)        # Crossover Start
    for i in range(0,20):
        x_i = randint(0,20)
        y_i = randint(0,20)
        x,y=crossOver(list[x_i],list[y_i])
        # print list[x_i], setScore(list[x_i])
        # print list[y_i], setScore(list[y_i])
        # print x, setScore(x)
        # print y, setScore(y)
        list.append(x)
        list.append(y)          # Crossover End
    rankPopulation(list)
    del list[50:]    
    for i in range(0,5):        # Mutation Start
        x_i = randint(5,49)
        x = mutation(list[x_i])
        list[x_i]=x             # Mutation End



if __name__ == "__main__":
    x = getInitialPopulation()    
    rankPopulation(x)
    print "Initial top 5 results in Population"
    count=1
    for i in x:
        count += 1
        print i, '  score:' ,setScore(i)
        if(count>5):
            break 
    # print(x[0],x[2])
    # c,d = crossOver(x[0],x[2])
    # m = mutation(x[0])
    for i in range(0,20):
        nextGeneration(x)    
    rankPopulation(x)
    count = 1
    print "Final top 5 results in Population"
    for i in x:
        count += 1
        print i, '  score:' ,setScore(i)
        if(count>5):
            break    