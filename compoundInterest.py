
#compoundInterest.py
#Abraham Schultz
#Spring 2017
#last edited 4/27/17 6:09pm
#this is an I-P-O porgram written in python which calculates compounded interest

print("This is a compound interest calculator")
#get the principal input from user
principal = int(input('Enter the principal amount in dollars: '))
print('You entered : ', principal,'$')
#echo to user


times_per_year = int(input('Enter the amount of times per years interest is compounded: '))
years = int(input('Enter the amount of years principal is to be compounded: '))
rate = float(input('enter the rate of interest as a decimal number that is less then 1 : '))

    #this is a function which calculates compound interest
def compound_interest(principal, rate, times_per_year, years):
    # (1 + r/n)
    body = 1 + (rate / times_per_year)
    # nt
    exponent = times_per_year * years
    # P(1 + r/n)^nt
    return principal * pow(body, exponent)
    #here i use the pow function built in to python

# Compute calling the compound-interest function 
result = compound_interest(principal, rate, times_per_year, years)
# Write result.
print(result)
#this empty input is to keep the command prompt open if running in a terminal
input()

