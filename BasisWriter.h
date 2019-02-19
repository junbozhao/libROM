/******************************************************************************
 *
 * Copyright (c) 2013-2019, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory
 * Written by William Arrighi wjarrighi@llnl.gov
 * CODE-686965
 * All rights reserved.
 *
 * This file is part of libROM.
 * For details, see https://computation.llnl.gov/librom
 * Please also read README_BSD_NOTICE.
 *
 * Redistribution and use in source and binary forms, with or without
 * modifications, are permitted provided that the following conditions are met:
 *
 *    o Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the disclaimer below.
 *    o Redistribution in binary form must reproduce the above copyright
 *      notice, this list of conditions and the disclaimer (as noted below) in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *    o Neither the name of the LLNS/LLNL nor the names of its contributors may
 *      be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
 * LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OR SUCH DAMAGE.
 *
 *****************************************************************************/

// Description: A class that writes basis vectors to a file.

#ifndef included_BasisWriter_h
#define included_BasisWriter_h

#include "Database.h"
#include <string>

namespace CAROM {

class SVDBasisGenerator;

/**
 * Class BasisWriter writes the basis vectors created by an SVDBasisGenerator.
 */
class BasisWriter {
   public:
      /**
       * @brief Constructor.
       *
       * @pre basis_generator != 0
       * @pre !base_file_name.empty()
       *
       * @param[in] basis_generator The generator of the basis vectors to be
       *                            written.
       * @param[in] base_file_name The base part of the name of the files
       *                           holding the basis vectors.
       * @param[in] db_format Format of the file to read.
       *                      One of the implemented file formats defined in
       *                      Database.
       */
      BasisWriter(
         SVDBasisGenerator* basis_generator,
         const std::string& base_file_name,
         Database::formats db_format = Database::HDF5);

      /**
       * @brief Destructor.
       */
      ~BasisWriter();

      /**
       * @brief Write basis vectors generated by d_basis_generator.
       */
      void
      writeBasis();

   private:
      /**
       * @brief Unimplemented default constructor.
       */
      BasisWriter();

      /**
       * @brief Unimplemented copy constructor.
       */
      BasisWriter(
         const BasisWriter& other);

      /**
       * @brief Unimplemented assignment operator.
       */
      BasisWriter&
      operator = (
         const BasisWriter& rhs);

      /**
       * @brief Basis generator whose basis vectors are being written.
       */
      SVDBasisGenerator* d_basis_generator;

      /**
       * @brief Database to which basis vectors are being written.
       */
      Database* d_database;

      /**
       * @brief Number of time intervals for which basis vectors have been
       * written.
       */
      int d_num_intervals_written;
};

}

#endif
