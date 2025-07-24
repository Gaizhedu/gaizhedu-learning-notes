import datetime as dt
class Bank:
    def __init__(self, account, money, date):
        self.account = account
        self.money = money
        self.date = date

    def sign_in(self):
        print(f"欢迎{self.account}登录，今天是{self.date}")

    def check_balance(self):
        print(f"您的余额为{self.money}元")

account_1 = Bank(account="axf118299", money=1390, date = dt.date.today())
account_2 = Bank(account="kwc821381", money=2730, date = dt.date.today())

account_1.sign_in()
account_1.check_balance()

# 输出：欢迎axf118299登录，今天是2025-07-13
# 您的余额为1390元