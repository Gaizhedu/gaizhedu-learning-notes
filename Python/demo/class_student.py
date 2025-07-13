class Student:
    def __init__(self, name, height, weight, age = 18):
        self.name = name
        self.height = height
        self.weight = weight
        self.age = age

    def introduce(self):
        print(f"学生{self.name}，年龄为{self.age}岁，身高为{self.height}cm，体重为{self.weight}kg")

    def change_weight(self, new_weight):
        self.weight = new_weight
        print(f"新体重为{self.weight}kg")

xiaoming = Student(name="小明", height="174", weight="56")
xiaoming.introduce()
xiaoming.change_weight(58)

# 输出：学生小明，年龄为18岁，身高为174cm，体重为56kg
# 新体重为58kg