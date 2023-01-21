;;; MERT GURSIMSIR
;;; 1901042646
;;; CSE 341 - PROGRAMMING LANGUAGES FALL 2022 

;;; You can run the REPL by --> clisp lexer.lisp            <----------------------
;;; You can read the file by -> clisp lexer.lisp test.txt   <----------------------

(defvar OCFLAG 0)   ;FLAG TO DETERMINE " IS OPEN OR CLOSE QUOTES
(defvar FILEFLAG 0) ;FLAG TO DETERMINE IF FILE READ OR INTERPRETER
(defvar FILECOMMENTFLAG 0)  ;FLAG TO ANALYSE FILE COMMENTS
(defvar toWrite (list)) ;LIST TO BE WRITTEN TO USER
(defvar inputLine)  ;INPUT LINE TAKEN FROM USER
(defvar FLAGF 0)    ;FLAG FOR FRACTION VALUES

;ANALYSING THE INPUT ACCORDING TO STRINGS AND RELATED FLAG
(defun automata(current nextChar lastChar flag)
    (case flag
        ;START FOR NEW INPUT
        ('START
            (if (or (char= (char current 0) #\space) (char= (char current 0) #\tab) (char= (char current 0) #\newline) (char= (char current 0) #\return))
                (setq current "")
                ;DETERMINE IF ZERO IS LEADING ZERO OR NOT
                (if (string-equal current "0")
                    (if (and (not (null nextChar)) (or (alpha-char-p (char nextChar 0)) (not (null (digit-char-p (char nextChar 0)))) ) )
                        (progn 
                            (if (char-equal (char nextchar 0) #\f)
                                (setq flag 'VALUEF)
                                (setq flag 'ERROR)
                            )
                        )
                        
                        (progn
                            (setq toWrite (append toWrite (list (list "0" "VALUEI"))))
                            (setq current "")
                        )
                    )
                    ;DETERMINE IF LINE IS COMMENT
                    (if (string-equal current ";")
                        (setq flag 'COMMENT)
                        ;DETERMINE IF INPUT IS VALUE
                        (if (not (null (digit-char-p (char current 0))))
                            (setq flag 'VALUE)
                            ;DETERMINE IF INPUT IS IDENTIFIER
                            (if (alpha-char-p (char current 0))
                                (setq flag 'IDENTIFIER)
                                (if (or (alpha-char-p (char current 0)) (char-equal (char current 0) #\_))
                                    (setq flag 'IDENTIFIER)
                                    (progn
                                        ;DETERMINE IF INPUT IS OPERATOR
                                        (let ((text (op-check current nextChar)))
                                            (if (not (eq text nil))
                                                (progn
                                                    (if (string-equal text "C")
                                                        (progn
                                                            ;SPECIFYING THE STRING AND WRITE IT
                                                            (if (= OCFLAG 0)
                                                                (progn
                                                                    (setq OCFLAG 1)
                                                                    (setq text "OP_OC")
                                                                    (setq pos (position #\" inputLine))
                                                                    (setq subLine (subseq inputLine (1+ pos) (length inputLine)))
                                                                    (if (not (is-char-exist #\" subLine))
                                                                        (progn
                                                                            (if (eq FILEFLAG 1)
                                                                                (write toWrite)
                                                                            )
                                                                            (format t "~%ERROR --> INVALID QUOTES~%" subLine)
                                                                            (bye)
                                                                        )
                                                                    )
                                                                    (setq posEnd (position #\" subLine))
                                                                    (setq strValue (subseq subLine 0 posEnd))
                                                                    (setq toWrite (append toWrite (list (list "\"" "OP_OC"))))
                                                                    (setq toWrite (append toWrite (list (list strValue "VALUESTR"))))
                                                                    (setq toWrite (append toWrite (list (list "\"" "OP_CC"))))
                                                                    
                                                                    (setq OCFLAG -1)
                                                                    (setq inputLine (subseq subLine (1+ posEnd) (length subLine)))
                                                                    (return-from automata nil)
                                                                )
                                                                (progn 
                                                                    (setq OCFLAG 0)
                                                                    (setq text "OP_CC")
                                                                )
                                                            )
                                                        )
                                                    )
                                                    (setq toWrite (append toWrite (list (list current text))))
                                                    (setq current "")
                                                )
                                                (if (string-equal current "*")
                                                    (setq flag 'MULTIPLICATION)
                                                    (setq flag 'ERROR)
                                                )
                                            )
                                        )
                                    )
                                    
                                )
                            )
                        )
                    )
                )
            )
        )
        ('MULTIPLICATION
            ;SPECIAL SITUATION FOR THE MULTIPLICATION AND DOUBLE MULTIPLICATION
            (let ((text (op-check current nextChar)))
                (if (not (eq text nil))
                    (progn
                        (setq flag 'START)
                        (setq toWrite (append toWrite (list (list "**" text))))
                        (setq current "")
                    )
                )
            )
        )
        ('COMMENT
            ;DETERMINING IF THE INPUT IS A COMMENT
            (if (string-equal current ";;")
                (setq flag 'COMMENTFLAG)
                (setq flag 'ERROR)
            )
        )
        ('COMMENTFLAG
            ;PRINTING OUT THE COMMENT LINE
            (setq lcTemp (char lastChar 0))
            (if (not (char-equal lcTemp #\newline))
                (if (eq FILEFLAG 1)
                    (progn
                        (setq state 'START)
                        (setq FILECOMMENTFLAG 1)
                        (setq firstElement (subseq inputLine (+ 2 (position #\; inputLine)) (length inputLine)))
                        (setq toWrite (append toWrite (list (list firstElement "COMMENT"))))
                        (setq current "")
                    )
                    (progn
                        (setq state 'START)
                        (setq firstElement (subseq inputLine (+ 2 (position #\; inputLine)) (length inputLine)))
                        (setq toWrite (append toWrite (list (list firstElement "COMMENT"))))
                        (write toWrite)
                        (terpri)
                        (setq current "")
                        (no-file-start)
                    )   
                )
            )
        )
        ('IDENTIFIER
            ;DETERMINING IF INPUT IS A GOOD IDENTIFIER OR IF SITUATION RESULTS IN ERROR
            (setq temp (subseq current 0 (1- (length current))))
            (if (or (char= (char lastChar 0) #\space) (char= (char lastChar 0) #\tab) (char= (char lastChar 0) #\newline) (char= (char lastChar 0) #\return))
                (progn
                    (setq flag 'START)
                    (if (keyword-check (string-right-trim " " temp))
                        (setq toWrite (append toWrite (list (list temp (keyword-check temp)))))
                        (setq toWrite (append toWrite (list (list temp "IDENTIFIER"))))
                    )
                    (setq current lastChar)
                )
                (if (op-check lastChar nil)
                    (progn
                        (setq flag 'START)
                        (if (keyword-check temp)
                            (setq toWrite (append toWrite (list (list temp (keyword-check temp)))))
                            (setq toWrite (append toWrite (list (list temp "IDENTIFIER"))))
                        )
                        (setq listValue (automata lastChar nextChar (subseq lastChar (1- (length lastChar)) (length lastChar)) flag))
                        (setq flag (nth 1 listValue))
                        (setq current (car listValue))
                    )
                    ;ELIMINATING INCONVENIENT INPUT
                    (if (not (or (alpha-char-p (char lastChar 0)) (not (null (digit-char-p (char lastChar 0)))) (char-equal (char lastChar 0) #\_)))
                        (setq flag 'ERROR)
                    )
                )
            )
        )
        ('VALUE
            ;CHECK IF GIVEN INPUT IS SUITABLE VALUE OR NOT
            (if (or (char= (char lastChar 0) #\space) (char= (char lastChar 0) #\tab) (char= (char lastChar 0) #\newline) (char= (char lastChar 0) #\return))
                (progn
                    (setq flag 'START)
                    (if (null (digit-char-p (char current (1- (length current))))) (setq current (subseq current 0 (1- (length current)))))
                    (setq toWrite (append toWrite (list (list (string-right-trim " " current) "VALUEI"))))
                    (setq current "")
                )
                (if (op-check lastChar nil)
                    (progn
                        (setq flag 'START)
                        (if (null (digit-char-p (char current (1- (length current))))) (setq current (subseq current 0 (1- (length current)))))
                        (setq toWrite (append toWrite (list (list (string-right-trim " " current) "VALUEI"))))
                        (setq listValue (automata lastChar nextChar (subseq lastChar (1- (length lastChar)) (length lastChar)) flag))
                        (setq current (car listValue))
                        (setq flag (nth 1 listValue))
                    )
                    (if (null (digit-char-p (char lastChar 0)))
                        (progn
                            (if (char-equal (char lastChar 0) #\f)
                                (setq flag 'VALUEF)
                                (setq flag 'ERROR)
                            )
                            
                        )
                        
                    )
                )
            )
        )
        ('VALUEF
            ;CHECK IF GIVEN VALUE IS INTEGER OR NOT
            (if (not (null lastChar))
                (when (and (char-not-equal #\f (char lastChar 0)) (alpha-char-p (char lastChar 0)))
                    (format t "LEXICAL ERROR --> ~a~%" current)
                    (bye)
                )
            )
            (if (char-equal #\0 (char lastChar 0))
                (if (/= FLAGF 2) (setq FLAGF 1))
                (setq FLAGF 2)
            )
            (if (or (null nextChar) (char= (char lastChar 0) #\space) (char= (char lastChar 0) #\tab) (char= (char lastChar 0) #\newline) (char= (char lastChar 0) #\return) (char= (char nextChar 0) #\space) (char= (char nextChar 0) #\tab) (char= (char nextChar 0) #\newline) (char= (char nextChar 0) #\return))
                (progn
                    (when (= FLAGF 1)
                        (format t "ERROR --> UNPROPER DIVISOR~%")
                        (bye)
                    )
                    (setq flag 'START)
                    (setq toWrite (append toWrite (list (list (string-right-trim " " current) "VALUEF"))))
                    (setq current "")
                )
                (if (not (null nextChar))
                    (if (not (null (digit-char-p (char nextChar 0))))
                        (setq flag 'VALUEF)
                        (setq flag 'ERROR)
                    )
                )
            )
            
        )
    )
    (list current flag)
)

(defun is-char-exist(c str)
    (member c (coerce str 'list))
)

(defun keyword-check(param)
    ;CHECK IF INPUT IS KEYWORD OR NOT IN THE ORDER IT IS GIVEN IN HOMEWORK PDF
    (setq temp (string-downcase param))
    (if (string-equal temp "and")
        "KW_AND"
        (if (string-equal temp "or")
            "KW_OR"
            (if (string-equal temp "not")
                "KW_NOT"
                (if (string-equal temp "equal")
                    "KW_EQUAL"
                    (if (string-equal temp "less")
                        "KW_LESS"
                        (if (string-equal temp "nil")
                            "KW_NIL"
                            (if (string-equal temp "list")
                                "KW_LIST"
                                (if (string-equal temp "append")
                                    "KW_APPEND"
                                    (if (string-equal temp "concat")
                                        "KW_CONCAT"
                                        (if (string-equal temp "set")
                                            "KW_SET"
                                            (if (string-equal temp "deffun")
                                                "KW_DEFFUN"
                                                (if (string-equal temp "for")
                                                    "KW_FOR"
                                                    (if (string-equal temp "if")
                                                        "KW_IF"
                                                        (if (string-equal temp "exit")
                                                            "KW_EXIT"
                                                            (if (string-equal temp "load")
                                                                "KW_LOAD"
                                                                (if (string-equal temp "disp")
                                                                    "KW_DISP"
                                                                    (if (string-equal temp "true")
                                                                        "KW_TRUE"
                                                                        (if (string-equal temp "false")
                                                                            "KW_FALSE"
                                                                            nil
                                                                        )
                                                                    )
                                                                )
                                                            )
                                                        )
                                                    )
                                                )
                                            )
                                        )
                                    )
                                )
                            )
                        )
                    )
                )
            )
        )
    )
)

(defun op-check(current next)
    ;CHECK IF INPUT IS OPERATOR OR NOT IN THE ORDER IT IS GIVEN IN HOMEWORK PDF
    (if (string-equal current "+") 
        "OP_PLUS"
        (if (string-equal current "-") 
            "OP_MINUS"
            (if (string-equal current "/") 
                "OP_DIV"
                (if (and (string-not-equal next "*") (string-equal current "*")) 
                    "OP_MULT"
                    (if (string-equal current "(") 
                        "OP_OP"
                        (if (string-equal current ")") 
                            "OP_CP"
                            (if (string-equal current "**") 
                                "OP_DBLMULT"
                                (if (string-equal current "\"")
                                    "C"
                                    (if (string-equal current ",") 
                                        "OP_COMMA"
                                        nil
                                    )
                                )
                            )
                        )
                    )
                )
            )
        )
    )
)

(defun analysis (input &optional previous flag)
    ;ASSIGNING OPTIONAL PARAMETERS TO STARTING VALUES
    (if (eq previous nil)
        (setq previous "")
    )
    (if (eq flag nil)
        (setq flag 'START)
    )

    ;RETURNING PROPERLY FOR ZERO-LENGTH INPUT
    (if (= (length input) 0)
        (progn
            (automata (concatenate 'string previous "   ") nil "    " flag)
            (return-from analysis nil)
        )
    )

    ;ASSIGNING NEXT CHARACTER TO PROPER VALUE FOR 
    (if (= (length input) 1)
        (setq nextChar nil)
        (setq nextChar (subseq input 1 2))
    )

    ;ASSIGNING FIRST CHARACTER TO PROPER VALUE
    (setq firstChar (subseq input 0 1))

    ;ASSIGNING WORD TO FORMER CHARACTERS' STRING
    (setq word (concatenate 'string previous firstChar))

    ;RUNNING THE AUTOMATA
    (setq listValue (automata word nextChar (subseq word (1- (length word)) (length word)) flag))

    ;SPECIFYING THE FILE COMMENT
    (when (= FILECOMMENTFLAG 1)
        (setq FILECOMMENTFLAG 0)
        (return-from analysis nil)
    )
    
    (setq flag (nth 1 listValue))

    ;HANDLE THE ERRORS AND EXIT FROM THE PROGRAM
    (if (eq flag 'ERROR)
        (progn
            (if (string-equal (subseq word 0 1) "0")
                (setq word (concatenate 'string word (subseq input 1 2)))
            )
            (write toWrite)
            (terpri)
            
            (format t "LEXICAL ERROR --> ~a~%" word)
            (bye)
        )
    )
    (setq word (string-left-trim " " (car listValue)))

    ;CONTINUING RECURSIVELY
    (if (eq OCFLAG -1)
        (progn
            (setq OCFLAG 0)
            (analysis inputLine)
        )
        (analysis (subseq input 1 (length input)) word flag)
    )  
)

(defun no-file-start()
    ;STARTING OF THE LEXICAL ANALYSIS - REPL
    (setq toWrite (list))
    (setq input (read-line))
    (setq inputLine input)
    (if (string-equal input "!exit")
        (format t "Have a wonderful day! ~%")
        (progn
            (analysis input)
            (write toWrite)
            (terpri)
            (no-file-start)
        )
    )
)

(defun file-start(name)
    ;STARTING OF THE LEXICAL ANALYSIS - FILE
    (setq FILEFLAG 1)
    (setq toWrite (list))
    (readFile name)
    (write toWrite)
)

(defun readFile (name)
    ;READ FILE LINE BY LINE
    (let ((in (open name :if-does-not-exist nil)))
        (when in
            (loop for line = (read-line in nil)
                while line do (setq inputLine line) (analysis line)
            )
        )
    )
)

(defun gppinterpreter()
    (if (eq *args* nil)
        (progn
            (format t "-----WELCOME TO PARSER----- ~%")
            (format t "---(print !exit to exit)--- ~%")
            (format t "--------------------------- ~%")
            (no-file-start)
        )
        (file-start (car *args*))
    )
)

(gppinterpreter)