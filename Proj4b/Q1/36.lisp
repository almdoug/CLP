(defun fatorial (n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
   (t (* n (fatorial (- n 1))))))

(defun fibonacci (n)
    (cond
    ((< n 1) nil)
    ((< n 3) 1)
    (t (+ (fibonacci (- n 1)) (fibonacci (- n 2))))))

(defun serieG (n)
    (cond
    ((< n 1) nil)             
    ((eql n 1) 1)
    ((evenp n) (- (serieG (- n 1)) (/ n (fatorial (fibonacci n)))))
    (t (+ (serieG (- n 1)) (/ n (fatorial (fibonacci n)))))))
