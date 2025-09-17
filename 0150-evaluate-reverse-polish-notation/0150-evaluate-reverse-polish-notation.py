class Solution:
    def performAritmethic(self, opt: str, x: int, y: int) -> int:
        if opt == "+":
            return x + y
        elif opt == "-":
            return x - y
        elif opt == '*':
            return x * y
        else:
            return int(x / y)

    def evalRPN(self, tokens: List[str]) -> int:
        sets = ("+", "-", "/", "*")
        stack = []

        for ch in tokens:
            if ch in sets:
                y = stack.pop()
                x = stack.pop()
                stack.append(self.performAritmethic(ch, x, y))
            else:
                stack.append(int(ch))

        return stack[0]