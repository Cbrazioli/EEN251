/**
 * @file pmc_maua.h
 * @author Rafael Corsi
 * @date 22/3/2016
 * @brief Funções para configurar o PMC do SAM4S
 */


/**
 * inclui o head do pmc
 */
#include "pmc_maua.h"

uint32_t _pmc_enable_clock_periferico(uint32_t ID){
    /**
     * @brief Existem dois registradores que configuram
     * os clocks dos perifericos, é necessário testarmos
     * antes para saber em qual deve ser salvo.
     *
     * O ID máximo para o PMC_PCER0 é 32
     */
    if(ID< 32){
        PMC->PMC_PCER0 = (1 << ID);
    }
    else{
        PMC->PMC_PCER1 = (1 << ID);
    }

    /**
     * @brief qual seria a situação que retornariamos 1 ?
     */
    return(0);
}

uint32_t _pmc_disable_clock_periferico(uint32_t ID){
    /**
     * @brief Existem dois registradores que configuram
     * os clocks dos perifericos, é necessário testarmos
     * antes para saber em qual deve ser salvo.
     *
     * O ID máximo para o PMC_PCER0 é 32
     */
    if(ID< 32){
        PMC->PMC_PCDR0 = (1 << ID);
    }
    else{
        PMC->PMC_PCDR1 = (1 << ID);
    }

    /**
     * @brief qual seria a situação que retornariamos 1 ?
     */
    return(0);
}

