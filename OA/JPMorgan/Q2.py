def balancedOrNot(expressions, maxReplacements):
    results=[]
    for i in range(len(expressions)):
        expression=expressions[i]
        replacements=maxReplacements[i]
        count=0
        unbalanced=False
        for char in expression:
            if char=="<": 
                count+=1
            elif char==">":
                if count==0:
                    if replacements<=0:
                        unbalanced=True
                        break
                    replacements-=1
                else:
                    count-=1
                    
        if count==0 and not unbalanced:
            results.append(1)
        else:
            results.append(0)
                
    return results