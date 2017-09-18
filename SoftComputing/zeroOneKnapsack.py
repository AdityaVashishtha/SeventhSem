from random import randint

CHROMOSOME_SIZE = 0
MAX_ONE_REQ = 32
LARGE_NUMBER = (2**MAX_ONE_REQ-1)
INITIAL_POPULATION_COUNT = 10
CROSSOVER_CHROMOSOME_SIZE = 3
MUTATION_BITS_COUNT = 3

def convertBinary(a):  
    binary=""  
    for i in range(32):
        bit = 0 if (a&(1<<i)==0) else 1
        binary += str(bit)        
    return binary[::-1]

def setScore(a,items,MAX_WT):
    count = 0
    wt = 0
    for i in range(0,len(a)):
        if(a[i]=='1'):
            wt += items[i][0]
            count += items[i][1]
    if(wt > MAX_WT):
        return 0
    return count

def crossOver(a,b):
    temp = (a[:CROSSOVER_CHROMOSOME_SIZE]) + b[CROSSOVER_CHROMOSOME_SIZE  : len(b)]
    temp2 = b[:CROSSOVER_CHROMOSOME_SIZE] + a[CROSSOVER_CHROMOSOME_SIZE : len(a)]
    return temp,temp2

def mutation(a):
    MUTATION_BITS_COUNT = int(round(CHROMOSOME_SIZE * 0.30));
    for i in range(0,MUTATION_BITS_COUNT):
        mutation_index = randint(0,CHROMOSOME_SIZE-1)
        if(a[mutation_index]=='1'):
            a=a[:mutation_index]+'0'+a[mutation_index+1:]
        else:
            a=a[:mutation_index]+'1'+a[mutation_index+1:]
    
    return a
    

def getInitialPopulation():
    string = ''
    x=[]
    for j in range(0,INITIAL_POPULATION_COUNT):
        string=''
        for i in range(0,CHROMOSOME_SIZE):
            temp = randint(1,10)
            if(temp > 5):
                string = string+'1'
            else:
                string = string+'0'
        x.append(string)
    return x


def rankPopulation(list,items,MAX_WT):
    for passnum in range(len(list)-1,0,-1):
        for i in range(passnum):
            if setScore(list[i],items,MAX_WT) < setScore(list[i+1],items,MAX_WT):
                temp = list[i]
                list[i] = list[i+1]
                list[i+1] = temp

def nextGeneration(list,items,MAX_WT):
    rankPopulation(list,items,MAX_WT)    
    for i in range(0,7):
        x_i = randint(4,7)
        y_i = randint(4,7)
        x,y=crossOver(list[x_i],list[y_i])
        # print list[x_i], setScore(list[x_i])
        # print list[y_i], setScore(list[y_i])
        # print x, setScore(x)
        # print y, setScore(y)
        list.append(x)
        list.append(y)
    for i in range(0,3):
        x_i = randint(0,9)
        x = mutation(list[x_i])
        list.append(x)
    rankPopulation(list,items,MAX_WT)
    del list[10:]

    
if __name__ == "__main__":
    items = [[24, 24],[10,18],[9,20],[5,8],[7,10]]
    MAX_WT = 40
    CHROMOSOME_SIZE = len(items)    
    CROSSOVER_CHROMOSOME_SIZE = CHROMOSOME_SIZE/2
    population = getInitialPopulation()
    rankPopulation(population,items,MAX_WT)
    count = 1
    print "Initial top 5 Item Values"
    for i in population:
        count+=1
        print i,setScore(i,items,MAX_WT)
        if(count>5):
            break
    for i in range(0,20):
        nextGeneration(population,items,MAX_WT)
    rankPopulation(population,items,MAX_WT)
    count = 1
    print "Final top 5 Item Values"
    for i in population:
        count += 1
        print i,setScore(i,items,MAX_WT)
        if(count>5):
            break 
    