(defun raiz (a n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
    (t (/ (+ (raiz a (- n 1)) (/ 3 (raiz a (- n 1)))) 2))))
