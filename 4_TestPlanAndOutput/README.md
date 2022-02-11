# Test Plan


## High Level Test Plan

| Test ID | Description | Exp I/P | Exp O/P |	Actual Output | status |
| --- | --- | --- | --- | --- | --- |
| H_01 | Adding new patients details  | id,name | Record ipdated sucessfully | Record ipdated sucessfully | pass |
| H_02 | Delete existed  patient  record | id=? | id found | id found | pass | 
| H_03 | checking list records present in system| view records | list of records | list of records | pass |
| H_04 | Search for particular patient record in system  | enter patient id | Record found | Record found | pass |

## Low Level Test Plan



| Test ID | Description | Exp I/P | Exp O/P |	Actual Output | status |
| --- | --- | --- | --- | --- | --- |
| L_01 | Delete patient record not existed  | id | id not found | id not found | pass |
| L_02 | Login into the system | Password | Denied | Denied | pass | 
| L_03 | checking rooms availability| Room no | Room not available | Room not available | pass |