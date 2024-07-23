def solution(new_id):
    #step1
    new_id = new_id.lower()

    #step2
    step = ''
    for i in new_id:
        if ('a' <= i <= 'z') or ('0' <= i <= '9') or i == '-' or i == '_' or i == '.':
            step += i
    new_id = step

    #step3
    step = new_id[0]
    for i in range(1, len(new_id)):
        if new_id[i] == '.' and new_id[i-1] == '.':
            next
        else:
            step += new_id[i]
    new_id = step
    #step4
    if new_id[0] == '.':
        step = new_id[1:]
    if new_id[-1] == '.':
        step = step[:-1]
    new_id = step
    #step5
    if len(new_id) == 0:
        new_id = 'a'
    #step6
    if len(new_id) >= 16:
        new_id = new_id[:15]
        if(new_id[-1] == '.'):
            new_id = new_id[:-1]
    #step7
    while len(new_id) <= 2:
        new_id += new_id[-1]

    print(new_id)
    return new_id


if __name__ == '__main__':
    solution("z-+.^.")
