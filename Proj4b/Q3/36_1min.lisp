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


(defun calcular-serieG-ate-n (limite-59-segundos)
    (loop for n from 1
        while (< (get-internal-real-time) (+ *internal-time-units-per-second* limite-59-segundos))
        do (let ((resultado (serieG n)))
                (format t "n: ~d, resultado: ~a~%" n resultado))))

(calcular-serieG-ate-n 59)
