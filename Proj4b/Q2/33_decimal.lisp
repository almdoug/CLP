(defun raiz (a n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
    (t (/ (+ (raiz a (- n 1)) (/ 3 (raiz a (- n 1)))) 2))))


(defun testar-precisao-raiz (a max-n tolerancia)
    (loop for n from 1 to max-n
        do (let* ((valor-lisp (raiz a n))
                    (valor-java (java:Math.sqrt a))
                    (diferenca (abs (- valor-lisp valor-java))))
                (format t "n: ~d, Lisp: ~a, Java: ~a, diferença: ~a~%"
                        n valor-lisp valor-java diferenca))
        until (< diferenca tolerancia)))
