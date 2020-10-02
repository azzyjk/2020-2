import os

def login():
    os.system("clear")
    id = input("아이디 : ")
    pw = input("패스워드 : ")
    
    directory = "./Users/"+id
    print("directory존재?")
    print(os.path.isdir(directory))
    if os.path.isdir(directory) == True:
        f = open(directory+"/password.txt", 'r')
        userPW = f.readline()
        if userPW == pw:
            os.system("clear")
            print(f"로그인에 성공했습니다. 반갑습니다 {id}님!")
            return True, id
        else : 
            os.system('clear')
            print("로그인에 실패했습니다. 다시 시도해주세요.")
            return False, None
    else:
        os.system('clear')
        print("잘못된 정보입니다. 다시 시도해주세요.")
        return False, None


def signUp():
    os.system("clear")
    id = input("사용하실 아이디를 입력해주세요 ")
    directory = "./Users/"+id

    while os.path.isdir(directory):
        print("이미 존재하는 아이디입니다.")
        id = input("사용하실 아이디를 입력해주세요 ")
        directory = "./Users/"+id

    pw = input("사용하실 비밀번호를 입력해주세요 ")
    
    os.makedirs(directory)
    userInfo = directory+"/password.txt"

    f = open(userInfo, 'w')
    f.write(pw)
    f.close()
    