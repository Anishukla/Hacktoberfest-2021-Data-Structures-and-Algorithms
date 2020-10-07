#Project Designed by Priyanshu Singh

#imports module
import bs4, requests, re, time
from tabulate import tabulate

#Main Program
#requests html file in raw data form from mohfw
res=requests.get('http://www.mohfw.gov.in/')
#converts in bs4 object file
ressoup=bs4.BeautifulSoup(res.text, 'lxml')
#extracts data from raw html using class name
listres=ressoup.select('.bg-blue strong')
listres1=ressoup.select('.bg-green strong')
listres2=ressoup.select('.bg-red strong')
listres3=ressoup.select('.bg-orange strong')
#using to extract time
regex=re.compile(r'\d+\s\w+\s\d+\S\s\d+\S\d+')
timestamp=regex.findall(str(ressoup))

#starts printing data
print('COVID19 Cases in INDIA Highlights')
print('*********************************', end='')
print('\n')
print('Total Confirmed Cases: ' + str(int(listres[0].getText())+int(listres1[0].getText())+int(listres2[0].getText())))
print('Active COVID19 Cases: ' + listres[0].getText())
print('Cured/Discharged Cases: ' + listres1[0].getText())
print('Death Cases: ' + listres2[0].getText())
print('Migrated COVID19 Cases: ' + listres3[0].getText(), end='')
print('\n')
print('COVID19 Cases Statistic State-wise')
print('**********************************', end='')
print('\n')

#start printing data in table using tabulate module
all=ressoup.select('.table.table-striped tbody')
nameregex=re.compile(r'<td>.*</td>')
final=nameregex.findall(str(all[0]))
headers=['S.No.', 'Name of State/UT', 'Total Conf. Cases', 'Cured/Discharged/Migrated', 'Death']
body=[]
lis=['1']
i=1
while  i<165:
    finalsoup=bs4.BeautifulSoup(final[i], 'lxml')
    if i%5!=0:
        lis.append(finalsoup.getText())
    else:
        body.append(tuple(lis))
        lis=[]
        lis.append(finalsoup.getText())
    i=i+1

#prints date and time of last updated.
print(tabulate(body, headers=headers), end='')
print('\n')
print('Source: MOHFW')
print('Last Updated: ', end='')
print(timestamp[0])
print('\n')
#input('Press ENTER to Exit ')
