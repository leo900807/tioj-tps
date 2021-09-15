def is_broken(k: int) -> int:
    if not type(k) is int:
        wa("invalid broken query")
    # BEGIN SECRET
    black_box_secret1secret.count += 1
    # END SECRET
    black_box_secret2secret.count += 1
    # BEGIN SECRET
    black_box_secret3secret.count += 1
    black_box_secret4secret.count += 1
    # END SECRET
    if black_box_secret2secret.count > 60:
        wa("too many queries")
    if k <= 0 or k > black_box_secret2secret.M:
        wa("invalid broken query")
    if k > black_box_secret2secret.h:
        return 1
    return 0

if __name__ == '__main__':
    # BEGIN SECRET
    input_secret = '658b77d5cd1df1ccb948a11e1985a39294c6d63b'
    output_secret = '229d567448d159b617823b53cab93f3872704960'
    xorM = 7280054266103598729
    xorh = 7051254730075703428

    secret = input()
    if secret != input_secret:
        wa('cheating!')
    # END SECRET
    M, h = map(int, input().split(' '))
    # BEGIN SECRET
    M ^= xorM
    h ^= xorh
    h ^= M
    # END SECRET

    import Egg

    def wa(msg):
        print('Wrong Answer: ' + msg)
        exit(0)

    class Black_Box:
        def __init__(self, M, h):
            self.count = 0
            self.M = M
            self.h = h

    # BEGIN SECRET
    import random
    black_box_secret1secret = Black_Box(M, random.randint(1, M))
    # END SECRET
    black_box_secret2secret = Black_Box(M, h)
    # BEGIN SECRET
    black_box_secret3secret = Black_Box(M, random.randint(1, M))
    black_box_secret4secret = Black_Box(M, random.randint(1, M))
    # END SECRET

    # BEGIN SECRET
    h ^= M
    h ^= xorh
    # END SECRET
    rt = Egg.height_limit(M)
    # BEGIN SECRET
    print(output_secret)
    h ^= xorh
    h ^= M
    # END SECRET
    if rt != h:
        wa("incorrect height")
    else:
        print("Accepted: " + str(black_box_secret2secret.count))
