class ContaBancaria:
    def __init__(self, saldo):
        self.saldo = saldo

    def verificar_saldo(self, valor):
        if self.saldo >= valor:
            return True
        else:
            return False


class Banco:
    def __init__(self):
        self.contas = []

    def adicionar_conta(self, conta):
        self.contas.append(conta)

    def sacar(self, valor):
        saldos_suficientes = True
        for conta in self.contas:
            if not conta.verificar_saldo(valor):
                saldos_suficientes = False
                print(f"Saldo insuficiente na conta {conta.__class__.__name__}")
        if saldos_suficientes:
            print(f"Saque de {valor} realizado com sucesso em todas as contas.")
        else:
            print("Saque não realizado devido a saldo insuficiente em pelo menos uma conta.")


conta_corrente = ContaBancaria(1000)
conta_salario = ContaBancaria(500)
conta_poupanca = ContaBancaria(1500)

banco = Banco()
banco.adicionar_conta(conta_corrente)
banco.adicionar_conta(conta_salario)
banco.adicionar_conta(conta_poupanca)

valor_saque = 700
banco.sacar(valor_saque)
