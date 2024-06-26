(defun factorial (n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
   (t (* n (factorial (- n 1))))))

(defun power (b e)
    (cond
    ((< e 0) nil)
    ((zerop e) 1)
   (t (* b (power b (- e 1))))))

(defun ex (x n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
    (t (+ (/ (power x n) (factorial n)) (ex x (- n 1))))))


(defun testar-precisao-ex (x max-n tolerancia)
    (loop for n from 1 to max-n
        do (let* ((valor-lisp (ex x n))
                    (valor-java (java:Math.exp x))
                    (diferenca (abs (- valor-lisp valor-java)))
                    (diferenca-relativa (/ diferenca (abs valor-java))))
                (format t "n: ~d, Lisp: ~a, Java: ~a, diferença relativa: ~a~%"
                        n valor-lisp valor-java diferenca-relativa))
        until (< diferenca-relativa tolerancia)))
