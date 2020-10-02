import os
from datetime import date

from login import *
from menu import *


def writeDiary(user, food):
    today = date.today()
    directory ="./Users/"+user+"/diary/"
    filename = directory+str(today)+".txt"

    if os.path.isfile(filename) == True:
        f = open(filename, "a")
    elif os.path.isfile(filename) == False:
        f = open(filename, "w")

    f.write(food+", ")
    f.close()

def loadDiary(user, date):
    directory ="./Users/"+user+"/diary/"
    filename = directory+str(date)+".txt"
    if os.path.isfile(filename) == True:
        f = open(filename, "r")
        test = f.readline()
        print(test.split(','))
        print(type(test))
        f.close()
    elif os.path.isfile(filename) == False:
        print("해당 날짜의 일기가 존재하지 않습니다.")
    
def showDiary(user):
    directory ="./Users/"+user+"/diary/"

    selectYear = 0
    selectMonth = 0
    selectDay = 0

    while selectDay == 0:
        selectYear = input("일지를 확인하고 싶은 연도를 입력해주세요.")
        selectYear = checkNumber(selectYear)
        if selectYear == 0:
            break
        if selectYear<70:
            selectYear += 2000
        if haveDiary(user, str(selectYear)) == False:
            continue
        selectMonth = input("일지를 확인하고 싶은 월을 입력해주세요.")
        selectMonth = checkNumber(selectMonth)
        if selectMonth == 0:
            break
        if haveDiary(user, str(selectYear)+"-"+str(selectMonth)) == False:
            continue
        

    # while selectMonth == -1:
    #     selectMonth = input("보고 싶은 달을 선택해주세요 : ")
    #     selectMonth = checkNumber(selectMonth)
    #     if selectMonth < 0 or selectMonth > 12:
    #         print("잘못된 값을 입력했습니다. 다시 입력해주세요.")
    #         selectMonth = -1

    # for i in os.listdir(directory):
    #     print(i.split(".")[0])
#day year도 선택하도록?

def haveDiary(user, date):
    res = 0
    directory ="./Users/"+user+"/diary/"

    for i in os.listdir(directory):
        if i.startswith(date):
           res += 1

    if res != 0 :
        return True
    else:
        print("해당 연 / 월에 해당하는 일기가 존재하지 않습니다. 다시 입력해 주세요.")
        return False 
        

def countDiary(user):
    directory ="./Users/"+user+"/diary/"
    monthFileCount = [0,0,0,0,0,0,0,0,0,0,0,0]
    fileCount = len(os.listdir(directory))
    for i in os.listdir("./Users/"+user+"/diary/"):
        monthFileCount[int(i.split("-")[1])-1] +=1
    return fileCount, monthFileCount

# showDiary("azzyjk")
# print(len(os.listdir("./Users/azzyjk/diary/")))
# writeDiary("azzyjk")

# os.system("ls Users/azzyjk | grep more")
user = None
loginStatus = False
task = None

os.system("clear")

def checkNumber(data):
    temp = 0
    for i in data:
        if i>='0' and i<='9':
            temp *= 10
            temp += int(i)
        else :
            print("잘못된 값이 존재합니다. 다시 입력해 주세요.")
            return -1
    return temp

today = date.today()
d1 = today.strftime("%Y")
print(today)
print(d1)

# showDiary("azzyjk")

# while task!='q':
#     showStartMenu()
#     task = input("번호를 선택해주세요.")
#     if task=='1':
#         loginStatus, user = login()
#     elif task=='2':
#         signUp()
#     elif task=='q':
#         break
#     else :
#         os.system("clear")
#         print("잘못 선택했습니다. 다시 선택해주세요.")
    
#     while loginStatus==True and task!="q":
#         showMainMenu()
#         task=input("메뉴를 선택해주세요")
#         if task == '1':
#             writeDiary(user, "chicken")
#         elif task == "2":
#             loadDiary(user, "2020-09-18")
#         elif task == 3:
#             pass
#         elif task == 'q':
#             break
#         else:
#             os.system('clear')
#             print("잘못 선택했습니다. 다시 선택해주세요.")
        
print("프로그램을 종료합니다.")


# def showDiary(user):
#     directory ="./Users/"+user+"/diary/"
#     month = 1
#     selectYear = -1
#     selectMonth = -1
#     selectDay = -1
    
#     fileCount, monthFileCount = countDiary(user)
#     print(f"총 {fileCount} 개의 일기가 있습니다.")

#     for i in monthFileCount:
#         print(f"{month}월 : {i}개")
#         month +=1

#     while selectMonth == -1:
#         selectMonth = input("보고 싶은 달을 선택해주세요 : ")
#         selectMonth = checkNumber(selectMonth)
#         if selectMonth < 0 or selectMonth > 12:
#             print("잘못된 값을 입력했습니다. 다시 입력해주세요.")
#             selectMonth = -1