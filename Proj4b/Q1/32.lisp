(defun fat (n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
   (t (* n (fat (- n 1))))))

(defun power (b e)
    (cond
    ((< e 0) nil)
    ((zerop e) 1)
   (t (* b (power b (- e 1))))))

(defun ex (x n)
    (cond
    ((< n 0) nil)
    ((zerop n) 1)
    (t (+ (/ (power x n) (fat n)) (ex x (- n 1))))))
