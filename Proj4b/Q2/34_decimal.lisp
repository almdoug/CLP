(defun seriePI (n)
    (cond
    ((< n 1) nil)
    ((eql n 1) 4)
    ((evenp n) (- (seriePI (- n 1)) (/ 4 (- (* n 2) 1))))
    (t (+ (seriePI (- n 1)) (/ 4 (- (* n 2) 1))))))


(defun testar-precisao-seriePI (max-n tolerancia)
    (loop for n from 1 to max-n
        do (let* ((valor-lisp (seriePI n))
                    (valor-java java:Math.PI)
                    (diferenca (abs (- valor-lisp valor-java))))
                (format t "n: ~d, Lisp: ~a, Java: ~a, diferença: ~a~%"
                        n valor-lisp valor-java diferenca))
        until (< diferenca tolerancia)))
