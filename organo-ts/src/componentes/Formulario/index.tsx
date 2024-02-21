import { useState } from 'react'
import Botao from '../Botao'
import CampoTexto from '../CampoTexto'
import ListaSuspensa from '../ListaSuspensa'
import './Formulario.css'
import { IColaborador } from '../../compartilhados/interfaces/IColaborador'

import React from 'react'

interface FormularioProps {
    aoColaboradorCadastrar: (colaborador: IColaborador) => void
    times: string[]
}

const Formulario = ({ aoColaboradorCadastrar, times }: FormularioProps) => {

    const [nome, setNome] = useState('')
    const [cargo, setCargo] = useState('')
    const [imagem, setImagem] = useState('')
    const [time, setTime] = useState('')
    const [data, setData] = useState('')

    const aoSalvar = (evento: any) => {
        evento.preventDefault()

        const colaborador: IColaborador = {
            nome: nome,
            cargo: cargo,
            imagem: imagem,
            time: time
        }

        aoColaboradorCadastrar(colaborador)
        setNome('')
        setCargo('')
        setImagem('')
        setTime('')
        setData('')
    }

    return (
        <section className="formulario">
            <form onSubmit={aoSalvar}>
                <h2>Preencha os dados para criar o card do colaborador</h2>
                <CampoTexto 
                    obrigatorio={true}
                    label="Nome"
                    placeholder="Digite seu nome" 
                    valor={nome}
                    aoAlterado={valor => setNome(valor)}
                />
                <CampoTexto
                    obrigatorio={true}
                    label="Cargo"
                    placeholder="Digite seu cargo" 
                    valor={cargo}
                    aoAlterado={valor => setCargo(valor)}
                />
                <CampoTexto
                    label="Imagem"
                    placeholder="Digite o endereço da imagem" 
                    valor={imagem}
                    aoAlterado={valor => setImagem(valor)}
                />
                <CampoTexto
                    label="Data"
                    placeholder="Data de entrada do time" 
                    tipo='date'
                    valor={data}
                    aoAlterado={valor => setData(valor)}
                />
                <ListaSuspensa
                    required={true}
                    label="Time" 
                    itens={times}
                    valor={time}
                    aoAlterado={valor => setTime(valor)}
                />
                <Botao>
                    Criar Card
                </Botao>
            </form>
        </section>
    )
}

export default Formulario