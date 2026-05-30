this is a classic transaction probelms , but with chain of debt records
our goal is to find net_balance per person .

and that would be the diff between money they should get - money they should give .

net_bal[person] = money to receive - money to give

eg :
[
    ["Tom", "Jerry", 1000],
    ["Jerry", "Spike", 1000],
    ["Spike", "Tom", 500]
]

this shows that 
tom re 500 , pays 1000 = 500 - 1000 = -500
jerry re 1000 pays 1000 = 1000 - 1000
spike re 1000 pays 500 = 1000 - 500 = 500

now we have to balance the transation 

which will lead us with 

top pays 500 to spike :::::::::::

gaols::
1) calculate net balance 
2) match debtors to with creditor using greedy algo 
3) create direct transaction 

./././././././././././././././././././.

constraints to handle --
1) since the input vector is all strings we have to convert the amount to long long
2) it is necessary to use long long 
3) we would need to use pair to hook up debt and debtors , credit and creditors


----Time and Space Complexity ----
IF --
    n = number of transactions
    p = number of unique people

Time Complexity
    ----O(n + p)

Space Complexity
    ----O(p)


