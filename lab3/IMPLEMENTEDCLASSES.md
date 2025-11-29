```text

ClassName attribure_count methods_count:
assotiations

1. Account Limit 2 3 ->

2. AccountTransaction 1 1 -> Transaction, BankAccount

3. AccountType 3 ->

4. BankAccount 8 10 -> Currency, AccountType, Customer, DataManager

5. Credit 23 21 -> CreditPayment, CreditAccount, Customer, DataManager, Currency

6. CreditPayment 1 2 -> Transaction, Credit

7. Currency 3

8. CurrencyConverter 2 2 -> Currency

9. CurrencyExchange 4 -> Currency

10. CurrencyConverter 2 1

11. CurrentAccount 2 2 -> Overdraft, BankAccount

12. Overdraft 9 6 -> CurrentAccount

13. Receipt 8 1 -> Currency, TransactionType, TransactionStatus

14. SavingsAccount 4 2 -> BankAccount

15. TransactionType 5

16. TransactionStatus 3

17. Transaction 7 4 -> BankAccount, TransactionType, TransactionStatus, Currency, DataManager

18. BoxStatus 3

19. BankSafeBox 6 12 -> Customer, BoxStatus

20. ATMState 4

21. ATM 6 9 -> ATMState, ATMStorage, Card, DataManager

22. ATMStorage 1 2 -> Currency, Nominal 

23. CardType 3

24. CardStatus 5

25. Card 12 9 -> Cashback, BankAccount, PaymentSystem, ExpirationDate, CardStatus

26. CardNumGen 0 3

27. Cashback 4 4 -> Card

28. ExpirationDate 3 3 0

29. InternetBanking 6 12 -> Card, DataManager

30. PasswordValidator 0 1

31. PaymentSystem 4

32. PinGen 0 2

33. Terminal 6 4 -> Card, Currency, DataManager

34. Address 7 5

35. Contact 3 3 -> Customer, BankAccount

36. Customer 13 23 -> Card, BankAccount, DataManager, Credit, Wallet

37. VerificationService 0 4

38. DataManager 6 5 -> BankAccount, Credit, Customer, Transaction, CurrencyConverter, GeneratorID

39. FAQ 3 3 -> FAQAnswer

40. FAQAnswer 2 2 -> FAQ 

41. GeneratorID 1 2 

42. Getter 0 2

43. TimeGetter 0 21

44. BanknoteValidator 1 1 -> Nominal, Currency

45. CalculatingMachine 0 1
  
46. CurrencyRateTableau 0 1

47. Nominal 9

48. Money 2 3 -> Currency, Nominal

49. MoneyPrinter 1 1 -> BanknoteValidator

50. Wallet 1 2 -> Currency, Nominal

193 метода

18 исключений

1. Exception
2. ExceptionIncorrectAmount
3. ExceptionFrozenAccount
4. ExceptionTimeError
5. ExceptionIncorrectPrice
6. ExceptionSafeBoxError
7. ExceptionIncorrectCreditPaymentAmount
8. ExceptionIncorrectDayCount
9. ExceptionPinError
10. ExceptionCardActivationError
11. ExceptionCardFreezeError
12. ExceptionCardBlockError
13. ExceptionATMError
14. ExceptionExpirationDateError
15. ExceptionIncorrectAccountType
16. ExceptionVerificationError
17. ExceptionInternetBankingError
18. ExceptionIncorrectAccount
```