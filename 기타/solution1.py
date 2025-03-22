def solution(code):
    mode = 0
    answer = ''
    answer = list(answer)
    ret = list(code)
    for i in range(len(code)):
        if mode == 0:
            if ret[i] != '1':
                if i % 2 == 0:
                    answer.append(ret[i])
            else:
                mode = 1
        else:
            if ret[i] != '1':
                if i % 2 == 1:
                    answer.append(ret[i])
            else:
                 mode = 0
    answer = "".join(answer)
    if not answer:
        return "EMPTY"

    return answer
