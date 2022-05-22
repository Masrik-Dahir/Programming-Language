; ----------------------------------------------------
;  Masrik Dahir
;  Date: 04/03/2022
;
;  ---------------------------------------------------
;  Usage Guide
;  (1) load ('Assignment6.lisp')
;
; ----------------------------------------------------

; 1. Write a Common Lisp function named myList which creates 
; the following list and returns it
(
    ; Creating function myList()
    defun myList()

    ; Returning the list with a single quotation before (4 (7 22) "art" ("math" (8) 99) 100), so it returns without evaluating it                          
    '(4 (7 22) "art" ("math" (8) 99) 100)   
)

; 2. Write a Common Lisp function named leapYear which takes no required
; parameters and returns an ordered list containing all leap years from 1800 though 2021.
; The list of leapyears must be calculated, no points will be given for a hard-coded list.
(
    ; Creating function leapYear() with two optional (not required) variable-  from_year (by deafult 1800) and to_year (by deafult 2021) in the parameter 
    defun leapYear(&optional (from_year 1800) (to_year 2021))

        ; loop from from_year to to_year
        (loop for x from from_year to to_year 
        
        ; if the year is divisible by 4, it is a leap year
        when (=(mod x 4)0) 

        ; if the year is divisible by 100 or 400, it is a leap year
        when (or (/=(mod x 100)0) (=(mod x 400)0)) 

            ; all the leap year to the list. Since the loop increment seqencially, the the year on the list would be incremental. It satisfy the 
            ; order lsit requirement
            collect x
        )

)

; 3. Write a Common Lisp function named union- which takes two list
; parameters. union- returns a single list which contains the separate unique entities
; from both lists, with no duplication. You are not allowed to use the predefined union
; function for this function. 
(
    ; Creating function union- with two required parameter first_list and second_list
    defun union- (first_list second_list)

    ; IF the first list is nonempty
    (if (> (length first_list) 0) 

        ; IF the first element (member (car first_list)) of the first_list in in the second list    
        (if (member (first first_list) second_list)   

            ; IF yes, we union-() the next all elelments of first_list to second_list
            (union- (rest first_list) second_list)

            ; ELSE we add the first element of the first_list to second list and 
            ; union-() the second list and next all elelments of first_list
            (union- (rest first_list) 
                (append second_list (list (first first_list) ) ) 
            )  
        )

        ; return the second_list (which appeded elements of first_list unless threre is a duplicate)
        (RETURN-FROM union- second_list)          
    )
)

; 4. Write a Common Lisp function named avg with a single parameter named
; aList. avg returns the average of all elements in aList. Assume all elements in aList are
; numbers. If given an empty list, avg should return NIL. The avg function must be tail
; recursive.
(

    ; Creating function avg with a required parameter aList and two optional parameter size and total
    ; size keeps tracks of the how many time we recursed through the aList
    ; total increments the sum of recursed values of aList
    defun avg(aList &optional (size 0) (total 0) )

        ; IF the size of aList greater than 0
        (if (> (length aList) 0)   

            ; find average of the next all elelments of aList, increment size by 1, increment the total
            ; by the first element of aList 
            (avg (rest aList) (+ size 1) (+ total (first aList) ) )   

            ; IF the size (not the size of the aList) greater than 0                              
            (if (> size 0)

                ; return the division of total by size (which is the average)
                (RETURN-FROM avg (/ total size) )      
            )
        )
)

; 5. Write a Common Lisp function named isType which takes a single
; parameter named dataType. isType will return an anonymous function which takes a
; single parameter and returns true if the parameters data type is the data type specified
; in dataType. Otherwise the anonymous function returns false.
(

    ; Creating function isType with a required parameter dataType
    defun isType(dataType)

        ; lambda allows to write anonymous functions so that we can pass value to dataType parameter
        (lambda (data) 

            ; returns an implementation-dependent result of anonymous function dataType
            (typep data dataType)
        )
)

; 6. Write a Common Lisp function named taxCalculator with three
; parameters: limit, rate, and values. limit and rate will be numbers, values will be a list.
; taxCalculator returns a list with the same elements and ordering of the values
; parameter EXCEPT every element which is greater than limit is multiplied by rate.
; Assume that all elements of the values list are numbers.
; BONUS: Make taxCalculator tail recursive
(
    ; Creating function taxCalculator with three required parameter limit, rate, and values and another optinal parameter result
    ; result contains the updated value of values list after tax operatons
    defun taxCalculator(limit rate values &optional result)

        ; IF the size of values list greater than 0
        (if (> (length values) 0) 

            ; IF the first element of values is greater than limit
            (if (> (first values) limit) 

                ; IF true, we recurse taxCalculator with limit, rate, and the rest of the elemetns of the values list and
                ; On the optional list result, we add the new modified value after multiplying with the tax rate
                (taxCalculator limit rate (rest values) (append result (list (* (first values) rate))))

                ; IF false, we recurse taxCalculator with limit, rate, and the rest of the elemetns of the values list and
                ; On the optional list result, we add the value without any modification
                (taxCalculator limit rate (rest values) (append result (list (first values) )))
            )

            ; return the optinoal result list (which cotains out modified list)
            (RETURN-FROM taxCalculator result)
        )
)


; 7. Write a Common Lisp function named clean which takes two parameters:
; aFunc and aList. aFunc will be a function and aList a list. aFunc is expected to be a
; function which takes a single parameter and returns a boolean value. clean will return
; a list which contains all values in aList which, when passed to aFunc, return true. If
; aList contains sublists, clean should create a new sublist with only the values which
; return true when passed to aFunc
(

    ; Creating function clean with two required parameter aFunc (a fucntion), and aList (a list of values and sublists) and 
    ; another optinal parameter true_list contains the value of aList list if their value on aFunc returns true, else
    ; donot append
    defun clean (aFunc aList &optional true_list)

        ; IF there is atleast one element in aList (else (first aList) would return false)
        (if (first aList)     

            ; IF (first aList) is not a list 
            (if (not (typep (first aList) 'list)) 

                ; IF the funcall aFunc returns false with the first element of the aList,
                (if (not (funcall aFunc (first aList) ))

                    ; We recurse clean with aFunc and the rest of the elemnts of aList and optinal true_list
                    (clean aFunc (rest aList) true_list)  

                    ; ELSE we recurse clean with aFunc and the rest of the elemnts of aList
                    ; and we append the first value of aList in true_list
                    (clean aFunc (rest aList) (append true_list (list (first aList) ) ) )                                     
                )

                ; ELSE (first aList) is a list we recurse the sublist as well
                ; We recurse the first value of sublist to clean and append it to true_list
                ; clean with aFunc and the rest of the aList elements with the true_list
                (clean aFunc (rest aList) (append true_list (list (clean aFunc (first aList) ) ) ) ) 
            )

            ; return the optinoal true_list (which cotains out modified list where its elements (including sublists) were returned true by clean)
            (RETURN-FROM clean true_list)
        )

)

;8. Define a Common Lisp macro named threeWayBranch, which takes three
; parameters: x, y, and z. All parameters will be lists containing an arbitrary number of
; sublists where the first sublist is a conditional.
; ( (conditional) (sublist-1) (sublist-2) … )
; (if a (do-x) (if b (do-y) (do-z)))
(

    ; Creating macro function threeWayBranch with three required parameter x, y, and z
    defmacro threeWayBranch (x y z)

        ; IF the first element of x list (conditional statement) returns true
        (if (first x) 

            ; we execute all subsequent sublists in parameter x
            (mapcan #'eval (rest x) ) 

            ; IF the first element of y list (conditional statement) returns true
            (if (first y)

                ; we execute all subsequent sublists in parameter y
                (mapcan #'eval (rest y) )  

                ; IF the first element of z list (conditional statement) returns true
                (if (first z)

                    ; we execute all subsequent sublists in parameter z
                    (mapcan #'eval (rest z) ) 
                )
            ) 
        )
)
