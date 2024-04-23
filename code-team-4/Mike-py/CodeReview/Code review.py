class User:
    def __init__(self, username, displayName, state, friends):
        self.username = username
        self.displayName = displayName
        self.state = state
        self.friends = friends

    def __str__(self):
        f = ""
        for i in range(0, len(self.friends)):
            f += "Friend" + str(i+1) + ": " + self.friends[i] + ", "
        return f"UserName: {self.username}, DisplayName: {self.displayName}, State: {self.state}, " + f

# u1 = User("goldenlover1", "Jane Doe", "CA", ["petpal4ever", "whiskerwatcher"])
# u2 = User("whiskerwatcher", "John Doe", "NY", ["goldenlover1"])
# u3 = User("petpal4ever", "Great Name", "WV", ["goldenlover1"])

# print(u1)
# print(u2)
# print(u3)

##########################################################################################################
class Posts:
    def __init__(self,postId,userName,viewType):
        self.postId = postId
        self.userName = userName
        self.viewType = viewType

    def __str__(self):
        return f"postId: {self.postId}, userName: {self.userName}, viewType: {self.viewType}"

# p1 = Posts("post1112","goldenlover1","friend")
# p2 = Posts("post2123 ","whiskerwatcher","friend ")
# p3 = Posts("post3298 ","petpal4ever "," public")

#3print(p1.postId)
# print(p2)
# print(p3)

globalUsers = []
globalPosts = []

def readUserLines (str):
    print(str)
    stringList = str.split(";")
    friends = stringList[3].removeprefix("[").removesuffix("]").split(",")
    u = User(stringList[0], stringList[1], stringList[2],friends)
    globalUsers.append(u)

def readPostLines (str):
    postsList = str.split(";")
    p = Posts(postsList[0],postsList[1],postsList[2])
    globalPosts.append(p)
option = '0'

while option  !='5':
    print('Options')
    print('1. Load input data.')
    print('2. Check visibility.')
    print('3. Retrieve posts.')
    print('4. Search users by location:')
    print('5. Exit:')

    option = input('Select an option: ')

    if option == '1':
        f1Name = input("Enter a path for User Info ")
        f2Name = input(" Enter path for Posts Info")
        
        file1 = open(f1Name, "r")
        lines = file1.readlines()
        for line in lines: 
            readUserLines(line)

        file2 = open(f2Name, "r")
        postLines = file2.readlines()
        for post in postLines:
            readPostLines(post)

    if len(globalPosts) > 0:
        
        if option == '2':
            postId = input('Enter post Id number: ')
            postsUserId = input('Enter a user id: ')
            print('Checking Posts Visibility ...')
            
            if postId == globalPosts[0]:
                if postsUserId == globalPosts[1]:
                    print('Access Permitted')
            else:
                print('Access Denied')

        elif option == '3':
            userName = input('Enter Username to get posts: ')
            if userName == "goldenlover1":
                print('Acess denied post Private')
            elif userName == 'whisker watcher':
                print('Acess denied post Private')
            elif userName == 'petpal4ever':
                print(p3.postId)

        elif option == '4':
            state = input('Enter 2 letters to find user from certain state: ')
            print('Searching For location ...')
            if state == 'ca' or state == 'CA':
                print(u1.displayName)
            elif state == 'ny' or state == 'NY':
                print(u2.displayName)
            elif state == 'wv' or state == 'WV':
                print(u3.displayName)

    elif option == '5':
        print('Exiting the system...')
