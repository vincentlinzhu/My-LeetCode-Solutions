def isValid(s):
    """
    :type s: str
    :rtype: bool
    """
    stack_open = []
    for char in s:
        if char == "(" or char == "[" or char == "{":
            stack_open.append(char)
        if char == ")":
            if len(stack_open) != 0 and stack_open[-1] == "(":
                stack_open.pop()
            else:
                return False
        if char == "]":
            if len(stack_open) != 0 and stack_open[-1] == "[":
                stack_open.pop()
            else:
                return False
        if char == "}":
            if len(stack_open) != 0 and stack_open[-1] == "{":
                stack_open.pop()
            else:
                return False
    if len(stack_open) == 0:
        return True
    return False

def main():
    s = "()[]}"
    print(isValid(s))

if __name__ == '__main__':
    main()