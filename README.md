# Cargo Stranding

## build
Clone the project and run `make`
```
git clone https://github.com/7Ji/CargoStranding
cd CargoStranding
make
```
The result binary is `cargo`

## Usage
Run `./cargo` to open the calculator to use its CLI

### Request
Enter `[Type]count(/total)(*duplicate)` to submit a request

The following types are supported:
 - `R` or `r` for resins
 - `M` or `m` for metals
 - `C` for ceramics
 - `c` for chemicals
 - `S` or `s` for special alloys

Examples
 - `M100` for 100 metals
 - `s1234/2600` for 1366 special alloys, useful since you don't need to calculate `2600-1234`
 - `c240*10` for 10 duplicated requests of 240 chemicals, useful since you don't need to enter multiple times
 - `r100/2300*6` for 6 duplicated requests of 2200 resins, useful since you don't need to calculate `2300-100`, and don't need to enter multiple times

### Report
Enter `report` to get a full table like the following:
```
=> Material request 1 or command: M100
  => Requested Metals * 100 (1 duplicates)
=> Material request 2 or command: S230/1400*20
  => Requested Special Alloys * 1170 (20 duplicates)
=> Material request 22 or command: report
  => Needed variants for current requests:
==========================================================
 Type           |   S |   M |   L | XL1 | XL2 | XL3 | XL4 
==========================================================
 Metals         |  50 | 100 | 200 | 400 | 600 | 800 |1000 
----------------+-----+-----+-----+-----+-----+-----+-----
                |     |   1 |     |     |     |     |     
==========================================================
 Special Alloys |  60 | 120 | 240 | 480 | 720 | 960 |1200 
----------------+-----+-----+-----+-----+-----+-----+-----
                |     |     |     |     |     |     |  20 
==========================================================
  => Total weight: 2410.0 kg, total volume: 122
```

### List
Enter `list` to get a full list of submitted requests and their IDs so you could get an idea of what's submitted and possibly delete them with their IDs
```
=> Material request 1 or command: M234
  => Requested Metals * 234 (1 duplicates)
=> Material request 2 or command: c240*10
  => Requested Chemicals * 240 (10 duplicates)
=> Material request 12 or command: S480*6
  => Requested Special Alloys * 480 (6 duplicates)
=> Material request 18 or command: list
  => Request 1: Metals * 234
    -> Metals (400) * 1
  => Request 2: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 3: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 4: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 5: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 6: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 7: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 8: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 9: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 10: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 11: Chemicals * 240
    -> Chemicals (240) * 1
  => Request 12: Special Alloys * 480
    -> Special Alloys (480) * 1
  => Request 13: Special Alloys * 480
    -> Special Alloys (480) * 1
  => Request 14: Special Alloys * 480
    -> Special Alloys (480) * 1
  => Request 15: Special Alloys * 480
    -> Special Alloys (480) * 1
  => Request 16: Special Alloys * 480
    -> Special Alloys (480) * 1
  => Request 17: Special Alloys * 480
    -> Special Alloys (480) * 1
```
### Delete
Enter `delete [id]` to delete a submitted request
```
=> Material request 1 or command: m1*365
  => Requested Metals * 1 (365 duplicates)
=> Material request 366 or command: clear
  => Cleared 365 requests
=> Material request 1 or command: m100*2
  => Requested Metals * 100 (2 duplicates)
=> Material request 3 or command: c1
  => Requested Chemicals * 1 (1 duplicates)
=> Material request 4 or command: C100
  => Requested Ceramics * 100 (1 duplicates)
=> Material request 5 or command: list
  => Request 1: Metals * 100
    -> Metals (100) * 1
  => Request 2: Metals * 100
    -> Metals (100) * 1
  => Request 3: Chemicals * 1
    -> Chemicals (30) * 1
  => Request 4: Ceramics * 100
    -> Ceramics (160) * 1
=> Material request 5 or command: delete 3
  => Deleted request 3
=> Material request 4 or command: list
  => Request 1: Metals * 100
    -> Metals (100) * 1
  => Request 2: Metals * 100
    -> Metals (100) * 1
  => Request 3: Ceramics * 100
    -> Ceramics (160) * 1
```
### Clear
Enter `clear` to delete all requests
```
=> Material request 1 or command: m1*365
  => Requested Metals * 1 (365 duplicates)
=> Material request 366 or command: clear
  => Cleared 365 requests
```