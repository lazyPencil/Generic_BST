# Generic_BST
# 자료구조 시간에 구현한 Generic BST입니다 (사용언어: C)
# Generic coding으로 했기 때문에 void * 자료형으로 data를 핸들링합니다. void* 를 비교할 수 없기 때문에
# 함수포인터를 활용하여 사용자가 원하는 자료형에 따라 compareint 혹은 comparestr을 사용할 수 있습니다.
# BST는 Root의 왼쪽트리에는 자신보다 작은 값을 가진 트리노드로 구성되고 오른쪽트리에는 자신보다 큰 값을 가진 트리노드로 구성됩니다.
# 그래서 Insert나 Delete를 할 때 주의가 필요합니다.
# test 소스파일도 같이 첨부되어 있습니다.
# 추가로 main_Problem2.c 프로그램의 경우 3가지 종류의 정렬순서를 사용자에게서 입력받은 뒤
# 사용자의 입력에 따라 BST를 구성해주는 프로그램입니다. TreeNode의 Data는 문자열로 구성됩니다.
