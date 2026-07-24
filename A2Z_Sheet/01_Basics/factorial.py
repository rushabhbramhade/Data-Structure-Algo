'''
Factorial Formula

n!=1×2×3×⋯×n

''' 


def fact(n):
    result = 1

    for i in range(1 , n + 1):
        result *= i

    return result

print(fact(5))
