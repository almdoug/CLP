%Douglas Benevides Almeida

(defun generate-random-list (n)
  (loop repeat n collect (random 1000)))

(defun trocar-elementos (lista)
  (if (or (null lista) (null (cdr lista)))
      lista
      (let ((primeiro (car lista))
            (segundo (cadr lista))
            (resto (cddr lista)))
        (if (> primeiro segundo)
            (cons segundo (cons primeiro (trocar-elementos resto)))
            (cons primeiro (trocar-elementos (cons segundo resto)))))))

(defun bubble-sort (lista)
  (let ((nova-lista lista))
    (loop for i from 0 below (length lista) do
          (setf nova-lista (trocar-elementos nova-lista)))
    nova-lista))

(defun inserir (x lista)
  (cond ((null lista) (list x))
        ((<= x (car lista)) (cons x lista))
        (t (cons (car lista) (inserir x (cdr lista))))))

(defun insertion-sort (lista)
  (if (null lista)
      nil
      (inserir (car lista) (insertion-sort (cdr lista)))))

(defun merge-sort (lista)
  "Ordena a LISTA usando o algoritmo Merge Sort."
  (if (pequena lista)
      lista
      (merge-list
       (merge-sort (metade-esquerda lista))
       (merge-sort (metade-direita lista)))))

(defun pequena (lista)
  "Verifica se a LISTA é pequena, ou seja, se está vazia ou tem apenas um elemento."
  (or (null lista) (null (cdr lista))))

(defun metade-direita (lista)
  "Retorna a metade direita da LISTA."
  (last lista (ceiling (/ (length lista) 2))))

(defun metade-esquerda (lista)
  "Retorna a metade esquerda da LISTA."
  (ldiff lista (metade-direita lista)))

(defun merge-list (lista1 lista2)
  "Combina duas listas ordenadas LISTA1 e LISTA2 em uma única lista ordenada."
  (merge 'list lista1 lista2 #'<))

(defun qsort (L)
  "Ordena a lista L usando o algoritmo Quick Sort."
  (cond
    ((null L) nil)
    (t (append
        (qsort (list< (car L) (cdr L)))
        (cons (car L) nil)
        (qsort (list>= (car L) (cdr L)))))))

(defun list< (a b)
  "Função auxiliar para comparar elementos."
  (cond
    ((or (null a) (null b)) nil)
    ((< a (car b)) (list< a (cdr b)))
    (t (cons (car b) (list< a (cdr b))))))

(defun list>= (a b)
  "Função auxiliar para comparar elementos."
  (cond
    ((or (null a) (null b)) nil)
    ((>= a (car b)) (list>= a (cdr b)))
    (t (cons (car b) (list>= a (cdr b))))))

(defun measure-sort-time (sort-function list)
  "Mede o tempo de execução de SORT-FUNCTION para ordenar a LIST."
  (let ((start-time (get-internal-real-time)))
    (funcall sort-function list)
    (/ (- (get-internal-real-time) start-time) internal-time-units-per-second)))

(defun measure-average-time (sort-function list-size num-trials)
  "Mede o tempo médio de execução de SORT-FUNCTION para listas de tamanho LIST-SIZE em NUM-TRIALS execuções."
  (let ((times (loop repeat num-trials
                     collect (measure-sort-time sort-function (generate-random-list list-size)))))
    (/ (reduce #'+ times) num-trials)))

(defun display-results ()
  "Exibe os resultados dos tempos médios de execução dos algoritmos de ordenação em formato CSV."
  (format t "Tamanho da Lista,Bubble Sort,Quick Sort,Insertion Sort,Merge Sort~%")
  (dolist (size '(10 100 1000))
    (let ((bubble-sort-time (measure-average-time #'bubble-sort size 10))
          (quick-sort-time (measure-average-time #'qsort size 10))
          (insertion-sort-time (measure-average-time #'insertion-sort size 10))
          (merge-sort-time (measure-average-time #'merge-sort size 10)))
      (format t "~d," size)
      (format t "~,6f," bubble-sort-time)
      (format t "~,6f," quick-sort-time)
      (format t "~,6f," insertion-sort-time)
      (format t "~,6f~%" merge-sort-time))))

(display-results)
