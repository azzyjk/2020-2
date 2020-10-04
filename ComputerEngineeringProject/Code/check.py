import re
import os
from datetime import date, datetime

def containNumber(word):
    res = re.search('[0-9]', word)
    if res == None:
        return False
    else :
        return True

def containLower(word):
    res = re.search('[a-z]', word)
    if res == None:
        return False
    else :
        return True

def containUpper(word):
    res = re.search('[A-Z]', word)
    if res == None:
        return False
    else :
        return True

def containOthers(word):
    res = re.search('[^0-9a-zA-Z]', word)
    if res == None:
        return False
    else :
        return True

def checkLen(minLen, maxLen, word):
    if len(word)>=minLen and len(word)<=maxLen:
        return True
    else:
        return False

def checkID(ID):
    if not containNumber(ID):
        print("아이디에 최소 1개의 숫자가 포함되어야 합니다. 다시 입력해주세요.") # 추가
        return False
    elif not containLower(ID):
        print("아이디에 최소 1개의 영문자(소문자)가 포함되어야 합니다. 다시 입력해주세요.") # 추가
        return False
    elif containUpper(ID):
        print("ID에 대문자는 들어갈 수 없습니다. 소문자만 입력해주세요,") # 추가
        return False
    elif not checkLen(4, 12, ID):
        if len(ID) < 4:
            print("아이디가 너무 짧습니다. 최소 4자 이상을 입력해주세요.")
        elif len(ID) > 12:
            print("아이디가 너무 깁니다. 4~12자 사이의 아이디를 입력해주세요.")
        return False
    elif containOthers(ID):
        print("아이디에 영문자(소문자)와 숫자외에 다른 문자가 올 수 없습니다. 다시 입력해주세요.") # 추가
        return False
    else:
        if os.path.isdir("./Users/"+ID):
            print("중복되는 ID가 존재합니다. 다시 입력해주세요.")
            return False
        else :
            return True
    
def checkPW(PW):
    if not containNumber(PW):
        print("비밀번호에 최소 1개의 숫자가 포함되어야 합니다. 다시 입력해주세요.") 
        return False
    elif not (containLower(PW) or containUpper(PW)):
        print("비밀번호에 최소 1개의 영문자가 포함되어야 합니다. 다시 입력해주세요.") 
        return False
    elif not checkLen(4, 12, PW):
        if len(PW) < 4:
            print("비밀번호가 너무 짧습니다. 최소 4자 이상을 입력해주세요.")
        elif len(PW) > 12:
            print("비밀번호가 너무 깁니다. 4~12자 사이의 비밀번호를 입력해주세요.")
        return False
    elif containOthers(PW):
        print("비밀번호에 영문자와 숫자외에 다른 문자가 올 수 없습니다. 다시 입력해주세요.") # 추가
        return True
    else:
        return True

def checkSex(sex):
    res = re.search(r'^남$|^남자$|^여$|^녀$|^여자$', sex)
    if res == None:
        print("잘못된 입력입니다. 다시 입력해주세요.")
        return False
    else:
        return True

def converSex(sex):
    res = re.search(r'^남$|^남자$', sex)
    if res != None:
        return "남자"
    else:
        return "여자"

def checkAge(age):
    res = re.search('[0-9]', age)
    if res == None:
        print("나이는 숫자만 입력 가능합니다. 다시 입력해주세요.") # 추가
        return False
    else:
        if not (int(age)>=0 and int(age)<=200):
            print("나이는 0~200사이의 자연수만 입력 가능합니다. 다시 입력해주세요") # 추가
            return False
        else :
            return True

def checkHeight(height):
    res = re.search('[0-9]', height)
    if res == None:
        print("키는 숫자만 입력 가능합니다. 다시 입력해주세요.") # 추가
        return False
    else:
        if not (int(height)<250 and int(height)>=1):
            print("키는 1이상 250미만의 정수만 입력가능합니다. 다시 입력해주세요.") # 추가
            return False
        else:
            return True

def checkWeight(weight):
    res = re.search('[0-9]', weight)
    if res == None:
        print("몸무게는 숫자만 입력 가능합니다. 다시 입력해주세요.") # 추가
        return False
    else:
        if not (int(weight)<200 and int(weight)>=1):
            print("몸무게는 1이상 200미만의 정수만 입력가능합니다. 다시 입력해주세요.") # 추가
            return False
        else :
            return True

def existID(id):
    directory = "./Users/"+id
    if os.path.isdir(directory) == True:
        return True
    else:
        print("존재하지 않는 아이디입니다. 메인메뉴로 돌아갑니다.") # 수정
        return False

def existFile(filename):
    if os.path.isfile(filename) == True:
        return True
    else:
        return False

def checkYYYYMM(YYYYMM):
    res = re.search('[^0-9]', YYYYMM)
    today = int(date.today().strftime('%Y%m'))
    year= YYYYMM[:4]
    month = YYYYMM[4:]
    if len(YYYYMM) < 6:
        print("입력된 인자의 수가 적습니다. 다시 입력해 주세요.")
        return False
    elif len(YYYYMM)>6:
        print("입력된 인자의 수가 많습니다. 다시 입력해 주세요.")
        return False
    elif res != None:
        print("숫자이외의 문자는 입력할 수 없습니다. 다시 입력해주세요.")
        return False
    elif int(YYYYMM) > today:
        print("현재 년월보다 빠른 일지는 존재하지 않습니다. 다시 입력해주세요.")
        return False
    elif not (int(year) >=1998 and int(year)<=2020):
        print("해당 연도는 지원하지 않습니다. 다시 입력해주세요.")
        return False
    elif not (int(month)>=1 and int(month)<=12):
        print("해당 월은 지원하지 않습니다. 다시 입력해주세요.")
        return False
    else:
        return True

def checkDD(YYYYMM, DD):
    res = re.search('[^0-9]', DD)
    year= int(YYYYMM[:4])
    month = int(YYYYMM[4:])
    if res!= None:
        print("숫자이외의 문자를 입력할 수 없습니다. 다시 입력해주세요.") # 수정
        return False
    else:
        try:
            checkDate = datetime(year, month, int(DD))
            return True
        except:
            print("해당 일은 존재하지 않습니다. 날짜를 확인 후 다시 입력해주세요.")
            return False
