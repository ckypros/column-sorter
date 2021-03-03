# Column-sorter
Program takes in command-line argument for a csv file and column # to sort by, and prints the sorted data using merge sort

## Example Output:
```
                      COLUMN 1                      COLUMN 2                     COLUMN 3
==========================================================================================
               Abraham Lincoln                          1861                    Republican
                Andrew Jackson                          1829                    Democratic
                Andrew Johnson                          1865              Democratic/Union
                  Barack Obama                          2009                    Democratic
             Benjamin Harrison                          1889                    Republican
               Calvin Coolidge                          1923                    Republican
             Chester A. Arthur                          1881                    Republican
                  Donald Trump                          2017                    Republican
          Dwight D. Eisenhower                          1953                    Republican
         Franklin D. Roosevelt                          1933                    Democratic
               Franklin Pierce                          1853                    Democratic
              George H.W. Bush                          1989                    Republican
                George W. Bush                          2001                    Republican
             George Washington                          1789                    Federalist
                   Gerald Ford                          1974                    Republican
              Grover Cleveland                          1885                    Democratic
              Grover Cleveland                          1893                    Democratic
               Harry S. Truman                          1945                    Democratic
                Herbert Hoover                          1929                    Republican
          James (Jimmy) Carter                          1977                    Democratic
             James A. Garfield                          1881                    Republican
                James Buchanan                          1857                    Democratic
                 James K. Polk                          1845                    Democratic
                 James Madison                          1809         Democratic Republican
                  James Monroe                          1817         Democratic Republican
                    John Adams                          1797                    Federalist
               John F. Kennedy                          1961                    Democratic
             John Quincy Adams                          1825         Democratic Republican
                    John Tyler                          1841                          Whig
             Lyndon B. Johnson                          1963                    Democratic
              Martin Van Buren                          1837                    Democratic
              Millard Fillmore                          1850                          Whig
                 Richard Nixon                          1969                    Republican
                 Ronald Reagan                          1981                    Republican
           Rutherford B. Hayes                          1877                    Republican
            Theodore Roosevelt                          1901                    Republican
              Thomas Jefferson                          1801         Democratic Republican
              Ulysses S. Grant                          1869                    Republican
             Warren G. Harding                          1921                    Republican
        William (Bill) Clinton                          1993                    Democratic
           William H. Harrison                          1841                          Whig
           William Howard Taft                          1909                    Republican
              William McKinley                          1897                    Republican
                Woodrow Wilson                          1913                    Democratic
                Zachary Taylor                          1849                          Whig
```

## Example input `presidentList.txt`
```
George Washington,1789,Federalist
John Adams,1797,Federalist
Thomas Jefferson,1801,Democratic Republican
James Madison,1809,Democratic Republican
James Monroe,1817,Democratic Republican
John Quincy Adams,1825,Democratic Republican
Andrew Jackson,1829,Democratic
Martin Van Buren,1837,Democratic
William H. Harrison,1841,Whig
John Tyler,1841,Whig
James K. Polk,1845,Democratic
Zachary Taylor,1849,Whig
Millard Fillmore,1850,Whig
Franklin Pierce,1853,Democratic
James Buchanan,1857,Democratic
Abraham Lincoln,1861,Republican
Andrew Johnson,1865,Democratic/Union
Ulysses S. Grant,1869,Republican
Rutherford B. Hayes,1877,Republican
James A. Garfield,1881,Republican
Chester A. Arthur,1881,Republican
Grover Cleveland,1885,Democratic
Benjamin Harrison,1889,Republican
Grover Cleveland,1893,Democratic
William McKinley,1897,Republican
Theodore Roosevelt,1901,Republican
William Howard Taft,1909,Republican
Woodrow Wilson,1913,Democratic
Warren G. Harding,1921,Republican
Calvin Coolidge,1923,Republican
Herbert Hoover,1929,Republican
Franklin D. Roosevelt,1933,Democratic
Harry S. Truman,1945,Democratic
Dwight D. Eisenhower,1953,Republican
John F. Kennedy,1961,Democratic
Lyndon B. Johnson,1963,Democratic
Richard Nixon,1969,Republican
Gerald Ford,1974,Republican
James (Jimmy) Carter,1977,Democratic
Ronald Reagan,1981,Republican
George H.W. Bush,1989,Republican
William (Bill) Clinton,1993,Democratic
George W. Bush,2001,Republican
Barack Obama,2009,Democratic
Donald Trump,2017,Republican
```
